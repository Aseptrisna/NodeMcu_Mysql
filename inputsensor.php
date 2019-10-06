<!-- 
Create By Omkabel.id
 -->
<?php
include ("Koneksi.php");

$data  =$_GET["data"];
$data2 =$_GET["data2"];
$data3 =$_GET["data3"];
$data4 =$_GET["data4"];
$data5 =$_GET["username"];

date_default_timezone_set('Asia/Jakarta');
$tanggal = date("Y-m-d H:i:s");
 
$sql = "INSERT INTO tb_sensor (suhu,detakjantung,sistolik,diastolik,username,tanggal) VALUES ('$data','$data2','$data3','$data4','$data5','$tanggal')";

if ($conn->query($sql) === TRUE) {
    echo "Sukses Tersimpan dong :) ".$data;


} else {
    echo "Error: ". $conn->error;
}
 
$conn->close();
?>