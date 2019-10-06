
<!-- 
Create By Omkabel.id
 -->
<?php
$host = "localhost"; 
$user = "root";     
$pass = "";          
$name = "db_kesehatan";      
 $conn = new mysqli($host, $user, $pass, $name);
 
if ($conn->connect_error) {
    die("Koneksi gagal: " . $conn->connect_error);
}
?>