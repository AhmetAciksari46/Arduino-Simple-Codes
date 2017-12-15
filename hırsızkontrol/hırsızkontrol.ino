#include <SPI.h> 
#include <Ethernet.h>
int led = 5;
int ldrpin = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192, 168, 1, 178 };                      
byte gateway[] = { 192, 168, 1, 1 };                  
byte subnet[] = { 255, 255, 255, 0 };                  
EthernetServer server(80);                            
String readString;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
   while (!Serial) {
     ;  
   }
//internet bağlantısı başlar.
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin(); //başlanır
  Serial.print("server is at "); 
  Serial.println(Ethernet.localIP()); 
} 
void loop() { 
  int ldr = analogRead(ldrpin);  
  EthernetClient client = server.available(); 
  if (client) { 
    while (client.connected()) { 
      if (client.available()) { 
        char c = client.read(); 
 
        if (readString.length() < 100) {
          readString += c;
         } 
         if (c == '\n') { 
              if(ldr > 800) {          
           Serial.println(readString); 
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type: text/html");
           client.println();
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           client.println("<TITLE>Arduino kapi kontrolu</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>KAPI ACIK</H1>");   
           client.println("<br />");
           client.println("</BODY>");
           client.println("</HTML>");
           delay(1);
           client.stop();
            readString="";  
         }
         else {
           Serial.println(readString); 
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type: text/html");
           client.println();
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           client.println("<TITLE>Arduino kapi kontrolu</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>KAPI KAPALI</H1>");   
           client.println("<br />");
           client.println("</BODY>");
           client.println("</HTML>");
           delay(1);
           client.stop();
            readString="";  
         }
           }
}
}
}
}

