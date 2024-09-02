#include <WebServer.h>


const char* ssid = "ITK-LAB.X";
const char* password = "K@mpusM3rdeka!";
const int pirPin1 = 13;
const int pirPin2 = 4;
const int ledPin1 = 12;
const int ledPin2 = 5;
WebServer server(80);
unsigned int peopleCount = 0;
const unsigned int maxPeopleCount = 10;
  // orang masuk dalam Ruangan


void HTMLControl() {
  int pirState1 = digitalRead(pirPin1);
  int pirState2 = digitalRead(pirPin2);


  String content = "<!DOCTYPE html><html><head><title>ESP32 Web Server</title>";
  content += "<meta http-equiv=\"refresh\" content=\"1\" />";
  content += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  content += "<style>.html{margin:auto;width:60%;border:3px solid #73AD21;padding:10px;text-align:center;}.green{background-image:-webkit-linear-gradient(top,#13fB04 0%,#58e343 50%,#ADED99 100%);}.red{background-image:-webkit-linear-gradient(top,#fb1304 0%,#e35843 50%,#edad99 100%);}.led{border-radius:5px;width:10px;height:10px;box-shadow:0px 0px 3px black;margin:auto;zoom:5;}.led:after{display:block;content:'';margin-left:auto;margin-right:auto;width:8px;height:6px;-webkit-border-top-right-radius:4px 3px;-webkit-border-top-left-radius:4px 3px;-webkit-border-bottom-right-radius:4px 3px;-webkit-border-bottom-left-radius:4px 3px;background-image:-webkit-linear-gradient(top,rgba(255,255,255,0.8) 0%,rgba(255,255,255,0.2) 100%);}</style>";
  content += "</head><body><div class=\"html\">";
  content += "<h1 style=\"background-color:DodgerBlue;\">WebServer Monitoring Gerakan dengan Sensor PIR</h1>";
  content += "<p><h2> Deteksi Jumlah Orang Dalam Ruangan</h2></p>";


  if (pirState1 == HIGH) {
    if (digitalRead(ledPin1) == LOW) {
      digitalWrite(ledPin1, HIGH);
      peopleCount++;  // Menambahkan Orang Masuk jika terdeteksi
    }
    content += "<p><div class=\"green led\"></div></p>";
    content += "<p><h4>Ada Gerakan pada Sensor 1 (Masuk)</h4></p>";
  } else {
    digitalWrite(ledPin1, LOW);
    content += "<p><div class=\"blue led\"></div></p>";
    content += "<p><h4>Tidak ada Gerakan pada Sensor 1 (Masuk)</h4></p>";
  }


  if (pirState2 == HIGH) {
    if (digitalRead(ledPin2) == LOW && peopleCount > 0) {
      digitalWrite(ledPin2, HIGH);
      peopleCount--;  // Mengurangi orang Ketika orang terdeteksi keluar
    }
    content += "<p><div class=\"red led\"></div></p>";
    content += "<p><h4>Ada Gerakan pada Sensor 2 (Keluar)</h4></p>";
  } else {
    digitalWrite(ledPin2, LOW);
    content += "<p><div class=\"blue led\"></div></p>";
    content += "<p><h4>Tidak ada Gerakan pada Sensor 2 (Keluar)</h4></p>";
  }


  content += "<p><h4>Jumlah Orang di Dalam Ruangan: " + String(peopleCount) + "</h4></p>";
  content += "</div></body></html>";
  server.send(200, "text/html", content);
}
  if (peopleCount >= maxPeopleCount) {
    content += "<p><h4 class=\"ruangan-penuh\">Ruangan Penuh</h4></p>";
  }




void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());


  server.on("/", HTMLControl);
  server.begin();


  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}


void loop() {
  server.handleClient();
  delay(2);
}
