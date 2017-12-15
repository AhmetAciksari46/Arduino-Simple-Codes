void setup()
{
pinMode(2, OUTPUT);
Serial.begin(9600);
}
void loop()
{
int nem = analogRead(A0);
if (nem <= 250)
{
Serial.println("Toprak ideal nem seviyesinin cok ustunde");
delay(500);
digitalWrite(2, LOW);
delay(2000);
}
else if (nem > 250 && nem <= 350)
{
Serial.println("Toprak ideal nem seviyesinin ustunde");
delay(500);
digitalWrite(2, LOW);
delay(2000);
}
else if (nem > 350 && nem <= 450)

{
Serial.println("Toprak ideal nem seviyesinde");
delay(500);
digitalWrite(2, LOW);
delay(2000);
}
else if (nem >450 && nem <= 550)
{
Serial.println("Toprak ideal nem seviyesinin altinda ve sulama sistemi devreye girecek");
digitalWrite(2, HIGH);
delay(2000);
}
else
{
Serial.println("Toprak ideal nem seviyesinin cok altinda ve sulama sistemi devreye girecek");
delay(500);
digitalWrite(2, HIGH);
delay(2000);
}
delay(2000);
}

