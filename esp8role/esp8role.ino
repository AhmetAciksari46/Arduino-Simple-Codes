#define ag_ismi "pheadrus"
#define ag_sifresi "ahmet123"
void setup()
{
  Serial.begin(115200); 
                       
  Serial.println("AT"); 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  delay(3000); 
 
  if(Serial.find("OK")){         
     Serial.println("AT+CWMODE=1"); 
     delay(2000);
     String baglantiKomutu=String("AT+CWJAP=\"")+ag_ismi+"\",\""+ag_sifresi+"\"";
    Serial.println(baglantiKomutu);
     delay(5000);
 }
 
   Serial.print("AT+CIPMUX=1\r\n");
   delay(200);
   Serial.print("AT+CIPSERVER=1,80\r\n");
   delay(1000);
}
void loop(){
  if(Serial.available()>0){
    if(Serial.find("+IPD,")){
      String metin = "<head> Hello World </head>";
      metin += "<br><a href=\" ?pin1=on\"><button type='button'>led 1 ac </button></a>"; 
      metin += "<br><a href=\" ?pin1=off\"><button type='button'>led 1 kapat </button></a>";     
       metin += "<br><a href=\" ?pin2=on\"><button type='button'>led 2 ac</button></a>"; 
      metin += "<br><a href=\" ?pin2=off\"><button type='button'>led 2 kapat </button></a>";     
       metin += "<br><a href=\" ?pin3=on\"><button type='button'>led 3 ac</button></a>"; 
      metin += "<br><a href=\" ?pin3=off\"><button type='button'>led 3 kapat </button></a>";     
       metin += "<br><a href=\" ?pin4=on\"><button type='button'>led 4 ac</button></a>"; 
      metin += "<br><a href=\" ?pin4=off\"><button type='button'>led 4 kapat </button></a>";     
       metin += "<br><a href=\" ?pin5=on\"><button type='button'>led 5 ac</button></a>"; 
      metin += "<br><a href=\" ?pin5=off\"><button type='button'>led 5 kapat </button></a>";     
       metin += "<br><a href=\" ?pin6=on\"><button type='button'>led 6 ac</button></a>"; 
      metin += "<br><a href=\" ?pin6=off\"><button type='button'>led 6 kapat </button></a>";     
       metin += "<br><a href=\" ?pin7=on\"><button type='button'>led 7 ac</button></a>"; 
      metin += "<br><a href=\" ?pin7=off\"><button type='button'>led 7 kapat </button></a>";     
       metin += "<br><a href=\" ?pin8=on\"><button type='button'>led 8 ac</button></a>"; 
      metin += "<br><a href=\" ?pin8=off\"><button type='button'>led 8 kapat </button></a>";     
      
      String cipsend = "AT+CIPSEND=";
      cipsend +="0";
      cipsend +=",";
      cipsend += metin.length();
      cipsend += "\r\n";
      Serial.print(cipsend);
      delay(500);
      Serial.println(metin);
      led_yakma();
      Serial.println("AT+CIPCLOSE=0");
      
    }
  }
}

void led_yakma(){
 String gelen ="";
 char serialdenokunan;
 while(Serial.available()>0){
 serialdenokunan = Serial.read();
 gelen +=serialdenokunan;
 
 }
 Serial.println(gelen);
 if((gelen.indexOf(":GET /?pin1=on")>1)){  
  digitalWrite(11,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin1=off")>1)){ 
  digitalWrite(11,LOW);                    
 }
 
  if((gelen.indexOf(":GET /?pin2=on")>1)){ 
  digitalWrite(4,HIGH);                 
 }
  if((gelen.indexOf(":GET /?pin2=off")>1)){ 
  digitalWrite(4,LOW);                    
 } if((gelen.indexOf(":GET /?pin3=on")>1)){  
  digitalWrite(5,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin3=off")>1)){ 
  digitalWrite(5,LOW);                    
 } if((gelen.indexOf(":GET /?pin4=on")>1)){  
  digitalWrite(6,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin4=off")>1)){
  digitalWrite(6,LOW);                    
 } if((gelen.indexOf(":GET /?pin5=on")>1)){  
  digitalWrite(7,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin5=off")>1)){ 
  digitalWrite(7,LOW);                   
 } if((gelen.indexOf(":GET /?pin6=on")>1)){  
  digitalWrite(8,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin6=off")>1)){ 
  digitalWrite(8,LOW);                   
 } if((gelen.indexOf(":GET /?pin7=on")>1)){  
  digitalWrite(9,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin7=off")>1)){ 
  digitalWrite(9,LOW);                    
 } if((gelen.indexOf(":GET /?pin8=on")>1)){ 
  digitalWrite(10,HIGH);                  
 }
  if((gelen.indexOf(":GET /?pin8=off")>1)){ 
  digitalWrite(10,LOW);                    
 }
 }
