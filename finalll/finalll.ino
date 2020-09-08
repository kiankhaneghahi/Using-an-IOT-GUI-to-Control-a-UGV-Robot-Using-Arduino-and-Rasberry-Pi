
#include <ESP8266WiFi.h>

const char* ssid = "SINA";
const char* password = "2560297061";

WiFiServer server(80);

int output_pin = 2;

void setup() {

 

  
  Serial.begin(38400);
  delay(10);

  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, 0);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
String readData="";
String readData2="";

if(Serial.available()>0)
{
  printf("available");
  readData=Serial.readString();
  readData2=readData.substring(readData.indexOf('@'),readData.indexOf('$'));
  Serial.flush(); 
  }
  



  if (req.indexOf("/Right") != -1) {
 
    digitalWrite(output_pin, 0);
    Serial.println('d');
     
  }
  else if (req.indexOf("/Left") != -1) {
    digitalWrite(output_pin, 0);
     Serial.println('a');

  }
else if (req.indexOf("/Forward") != -1) {
    digitalWrite(output_pin, 0);
    Serial.println('w');

  }
  else if (req.indexOf("/Backward") != -1) {
    digitalWrite(output_pin, 0);
    Serial.println('s');
   }
   else if (req.indexOf("/Stop") != -1) {
    digitalWrite(output_pin, 1);
    Serial.println("C:Stop");
  }
  client.flush();


  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += "<head>";
  s += "<meta charset=\"utf-8\">";
  s += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  s += "<script src=\"https://code.jquery.com/jquery-2.1.3.min.js\"></script>";
  s += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  s += "</head>";

  s += "<div class=\"container\">";
  s += "<h1>کنترل خودرو</h1>";
  s += "<div class=\"row\">";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:28px;border-radius:100%;height:100px;width:100px;\"type=\"button\" value=\"راست\" onclick=\"right()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:28px;border-radius:100%;height:100px;width:100px;\" type=\"button\" value=\"چپ\" onclick=\"left()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:28px;border-radius:100%;height:100px;width:100px;\" type=\"button\" value=\"جلو\" onclick=\"forward()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-success\"style=\"font-size:28px;border-radius:100%;height:100px;width:100px;\" type=\"button\" value=\"عقب\" onclick=\"backward()\"></div>";
  s += "<div class=\"col-md-2\"><input class=\"btn btn-block btn-lg btn-danger\"style=\"font-size:28px;border-radius:100%;height:100px;width:100px;\" type=\"button\" value=\"توقف\" onclick=\"stop()\"></div>";
  s += "</div></div>";
  s += "<h1>اطلاعات دریافت شده:</h1>";
  s += "<h1>"+readData2+"</h1>";
  

  s += "<script>function left() {$.get(\"/Left\");}</script>";
  s += "<script>function right() {$.get(\"/Right\");}</script>";
  s += "<script>function forward() {$.get(\"/Forward\");}</script>";
  s += "<script>function backward() {$.get(\"/Backward\");}</script>";
  s += "<script>function stop() {$.get(\"/Stop\");}</script>";


  client.print(s);
  delay(1);
  Serial.println("Client disconnected");
}
