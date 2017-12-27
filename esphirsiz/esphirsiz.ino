#define isim "WiFi_Ismi"
#define sifre "WiFi_Sifresi"
int led = 5; //ledin + kısmı dijital 5. pinde - kısmı gndde
int ldrpin = 0; //ldr sinyal pini A0 pininde VCC 5V, GND GND pinlerinde.
void setup()
{
  Serial.begin(115200); 
  pinMode(led, OUTPUT); //LED PİNİ ÇIKIŞ OLARAK TANIMLANIR
  digitalWrite(led, HIGH); //LED PİNİ SÜREKLİ AÇIK OLARAK TANIMLANIR
  Serial.println("AT");   
  delay(3000); 
  if(Serial.find("OK")){         
     Serial.println("AT+CWMODE=1"); 
     delay(2000);
     String baglantiKomutu=String("AT+CWJAP=\"")+isim+"\",\""+sifre+"\"";
    Serial.println(baglantiKomutu);    
     delay(5000);
 }
   Serial.print("AT+CIPMUX=1\r\n"); 
   delay(200);
   Serial.print("AT+CIPSERVER=1,80\r\n"); 
   delay(1000);
}
void loop(){
  int ldr = analogRead(ldrpin); //ldr tanımlamasının okunan analog değerler olduğu tanımlanır.
  if (ldr > 800){ // ldr değeri parlaklık algılıyorsa, kapı kapanmış ve elektrik iletimi sağlanıyorsa
  if(Serial.available()>0){  
    if(Serial.find("+IPD,")){  
      String metin = "<head> <h1>Kapi Kapali</h1> </head>";   // kapi kapali yazdır.
      String yollanacak_komut = "AT+CIPSEND=";  
      yollanacak_komut +="0";
      yollanacak_komut +=",";
      yollanacak_komut += metin.length();
      yollanacak_komut += "\r\n";
      Serial.print(yollanacak_komut);
      delay(500);
      Serial.println(metin);
      delay(1000);
      Serial.println("AT+CIPCLOSE=0"); //Server'ı kapatıyoruz.
    }
  }
  } else { // değil ise kapi acik yaz.
     if(Serial.available()>0){  
    if(Serial.find("+IPD,")){ 
      String metin = "<head> <h1>Kapi Acik</h1> </head>";  
      String yollanacak_komut = "AT+CIPSEND=";  
      yollanacak_komut +="0";
      yollanacak_komut +=",";
      yollanacak_komut += metin.length(); 
      yollanacak_komut += "\r\n";
      Serial.print(yollanacak_komut);
      delay(500);
      Serial.println(metin);
      delay(1000);
      Serial.println("AT+CIPCLOSE=0");
    }
  }
}
}
