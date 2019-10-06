#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int BPM,Sistolik,Diastolik,Suhu;
String delfita;
String Angga=delfita;
WiFiClient client;
String request_string;
const char* host ="192.168.43.71"; // ip computer agan, bisa di lihat ipv4 di CMD dengan perintah ipconfig
HTTPClient http;
void setup() {
s.begin(9600);
Serial.begin(9600);
 WiFi.disconnect();
//
   WiFi.begin("Skripsi2019","skripsi1234"); // nama wifi ssid dan Passwordnya
    while ((!(WiFi.status() == WL_CONNECTED))){
      delay(2000);
//
//   WiFi.begin("Arduino Bandar Lampung","ciumdululah1234"); // nama wifi ssid dan Passwordnya
//    while ((!(WiFi.status() == WL_CONNECTED))){
//      delay(2000);
    }
}
 
void loop() {
  delay(40000);

  s.write("s");
    BPM=s.read();
    Serial.println(BPM);
    delay(1000);
    Sistolik=s.read();
    Serial.println(Sistolik);
    delay(1000);
    Diastolik=s.read();
    Serial.println(Diastolik);
    delay(1000);
    Suhu=s.read();
    Serial.println(Suhu);
    delay(1000);


    if (BPM,Sistolik,Diastolik,Suhu > 0){
      kirimdata();
      }else{
         Serial.println("Data Tidak valid");
        }
    
}


void kirimdata(){
      delay(5000);
    if (!client.connect(host,80)) {
      Serial.println("Gagal Konek");
      return;
    }
    request_string = "/Api_ibuhamil/inputsensor.php?data=";
    request_string += Suhu;
    request_string += "&data2=";
    request_string += BPM;
    request_string += "&data3=";
    request_string += Sistolik;
    request_string += "&data4=";
    request_string += Diastolik;
    request_string += "&username=";
    request_string += "robby";
    Serial.print("requesting URL: ");
    Serial.println(request_string);
   client.print(String("GET ") + request_string + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
   
      unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  } 
      
      }

