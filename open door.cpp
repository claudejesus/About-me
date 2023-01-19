//any challenge or question ask me use// niyigabaclaujesus@gmail.com(0783456845)

//
#include <ESP8266WiFi.h>
#include <Servo.h>
Servo servo;
 
// const char* ssid = "CANALBOX-5FB2-2G";
// const char* password = "6nzjab56aQ";  

//const char* ssid = "Rwanda-ltd";
//const char* password = "VRT0931VRT"; 

const char* ssid = "jesus";// you must create this wifi and we connect your pc to it
const char* password = "jesus12345"; 


//const char* ssid = "Miheto";
//const char* password = "mht00998877"; 

WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
  servo.attach(D2); //Gpio-2 of nodemcu with pwm pin of servo motor
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 int value = 0;
 // Match the request

if (request.indexOf("/Req=0") != -1)  {
  servo.write(0); //Moving servo to 0 degree
  value=0;
}
if (request.indexOf("/Req=90") != -1)  {  
  servo.write(90); //Moving servo to 90 degree
  value=90;
}
if (request.indexOf("/Req=30") != -1)  {  
  servo.write(30); //Moving servo to 30 degree
  value=30;
}
if (request.indexOf("/Req=180") != -1)  { 
  servo.write(180); //Moving servo to 180 degree
  value=180;
}  

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1 align=center>WELCOME IN SMART SERVER RACK MOUNT</h1><br><br>");
  client.print("Current position  = ");
  client.print(value); 
  client.println("<br><br>");
//  client.println("<a href=\"/Req=0\"\"><button>Move to = 0 degree</button></a>");

 client.println("<a href=\"/Req=30\"\"><button>TURN ON SERVER </button></a>");
 
//  client.println("<a href=\"/Req=90\"\"><button>TURN ON SERVER </button></a>");
  
//  client.println("<a href=\"/Req=90\"\"><button>Move to = 90 degree</button></a>");
  client.println("<a href=\"/Req=180\"\"><button>TURN OFF SERVER</button></a>");
  
//  client.println("<a href=\"/Req=180\"\"><button>Move to = 180 degree</button></a><br/>");

  client.println("</html>");
  delay(1000);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
