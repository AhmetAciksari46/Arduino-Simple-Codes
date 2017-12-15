#define role  5
float sicaklik;  
float analoggerilim; 
int sicaklikpin=1; 

#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {0xB7, 0x17, 0x07, 0xFF, 0xCB, 0x43}; 
byte ip[] = { 192, 168, 1, 178 };                      
byte gateway[] = { 192, 168, 1, 1 };                   
byte subnet[] = { 255, 255, 255, 0 };                 
EthernetServer server(80);                             
String HTTP_req;          
byte deger = 25;  

void setup() {
  Serial.begin(9600);
   while (!Serial) {
     ;  
   }
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin(); 
      pinMode(role, OUTPUT);       
} 
void loop() {
  EthernetClient client = server.available(); 
  if (client) {  
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   
                char c = client.read(); 
                HTTP_req += c; 
                if (c == '\n' && currentLineIsBlank) {
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    client.println("<html>");
                    client.println("<head>");   
                    ProcessValue();
                    client.println("<title>kombi kontrol</title>");
                    client.println("</head>");
                    client.println("<body>");
                    client.println("<h1>Kombi yonetimi</h1><br>");
                    client.println("<form action=\"/\">");
                    client.println("<p>");
                    client.print  ("  Deger giriniz: <input type=\"number\" name=\"v\" min=\"0\" max=\"50\" value=\"");
                    client.print  (deger); 
                    client.print  ("\" length> <em>(0-50)</em><br>");
                    client.println("</p>");
                    client.println("<p><input type=\"submit\" value=\"ayarla\"></p>");
                    client.println("</form>");
                    client.println("</body>");
                    client.println("</html>");
                    Serial.print(HTTP_req);
                    HTTP_req = "";    
                    break;
                }
                if (c == '\n') {
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {                   
                    currentLineIsBlank = false;
                }
            } 
        } 
        delay(1);     
        client.stop();      
    } 
}
void ProcessValue()
{
 analoggerilim = analogRead(sicaklikpin); //A1'den değeri ölç
 analoggerilim = (analoggerilim/1023)*5000;//değeri mV'a dönüştr 
 sicaklik = analoggerilim /10,0;
    int start = -1;
    int stops = -1;
    char a = 0;
    String numasstr;
    int n;
    start = HTTP_req.indexOf("?v=");       
    if (start != -1) {
      n = start + 3; 
      while (a != ' ') {
        a = HTTP_req.charAt(n);
        numasstr += a;
        n++;
      }
      deger = numasstr.toInt();     
      if (deger < sicaklik) {
        digitalWrite(role, HIGH);
      } else {         
          digitalWrite(role, LOW);
        } 
        delay(5000);
      }  
}
