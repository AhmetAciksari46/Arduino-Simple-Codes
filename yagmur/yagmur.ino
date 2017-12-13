const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
    Serial.begin(9600);  
}
void loop() {
   int sensorOkuma = analogRead(A0);
   int deger= map(sensorOkuma, sensorMin, sensorMax, 0, 3);
 switch (deger) {
 case 0:    
    Serial.println("Kuru");
    break;
 case 1:    
    Serial.println("Yagmur Yagiyor");
    break;
 case 2:    
    Serial.println("Saganak Yagmur");
    break;
  }
  delay(1000);  
}
