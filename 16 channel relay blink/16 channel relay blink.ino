//Röle Pinlerine göre tanımlamalarımızı yapıyoruz.
#define RELAY01 2                        
#define RELAY02 3                        
#define RELAY03 4                        
#define RELAY04 5
#define RELAY05 6
#define RELAY06 7
#define RELAY07 8
#define RELAY08 39
#define RELAY09 41
#define RELAY10 43
#define RELAY11 45
#define RELAY12 47
#define RELAY13 49
#define RELAY14 51
#define RELAY15 53
#define RELAY16 9
void setup()
{    

  pinMode(RELAY01, OUTPUT);       
  pinMode(RELAY02, OUTPUT);
  pinMode(RELAY03, OUTPUT);
  pinMode(RELAY04, OUTPUT);
  pinMode(RELAY05, OUTPUT);
  pinMode(RELAY06, OUTPUT);
  pinMode(RELAY07, OUTPUT);
  pinMode(RELAY08, OUTPUT);
  pinMode(RELAY09, OUTPUT);
  pinMode(RELAY10, OUTPUT);
  pinMode(RELAY11, OUTPUT);
  pinMode(RELAY12, OUTPUT);
  pinMode(RELAY13, OUTPUT);
  pinMode(RELAY14, OUTPUT);
  pinMode(RELAY15, OUTPUT);
  pinMode(RELAY16, OUTPUT);
}
 
 void loop()
{
  //2 saniye arayla yanıp sönme kodunu yazıyoruz.
   digitalWrite(RELAY01,LOW);            
   delay(1000);                                      
   digitalWrite(RELAY01,HIGH);          
 
   digitalWrite(RELAY02,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY02,HIGH);          
 
   digitalWrite(RELAY03,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY03,HIGH);          
 
   digitalWrite(RELAY04,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY04,HIGH);                 
 
   digitalWrite(RELAY05,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY05,HIGH);          
 
   digitalWrite(RELAY06,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY06,HIGH);          
 
   digitalWrite(RELAY07,LOW);           
   delay(2000);                                      
   digitalWrite(RELAY07,HIGH);          
 
   digitalWrite(RELAY08,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY08,HIGH);          
 
   digitalWrite(RELAY09,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY09,HIGH);          
 
   digitalWrite(RELAY10,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY10,HIGH);          
 
   digitalWrite(RELAY11,LOW);           
   delay(2000);                                      
   digitalWrite(RELAY11,HIGH);          
 
   digitalWrite(RELAY12,LOW);           
   delay(2000);                                   
   digitalWrite(RELAY12,HIGH);          
 
   digitalWrite(RELAY13,LOW);           
   delay(1000);                                   
   digitalWrite(RELAY13,HIGH);          
 
   digitalWrite(RELAY14,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY14,HIGH);          
   
   digitalWrite(RELAY15,LOW);           
   delay(1000);                                     
   digitalWrite(RELAY15,HIGH);          
   
   digitalWrite(RELAY16,LOW);           
   delay(1000);                                      
   digitalWrite(RELAY16,HIGH);          
 }
