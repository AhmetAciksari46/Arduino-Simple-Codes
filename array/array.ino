byte ledpins[9]={2,3,4,5,6,7,8,9,13};

int i;

void setup() 

{
      for (i = 0; i < 10; i = i + 1) 
      {
          pinMode(ledpins[i], OUTPUT); 
      } 
 Serial.begin(9600); 
}

void loop()
{
      for (i = 0; i < 10; i = i + 1) 
        {
            digitalWrite(ledpins[i], LOW);
            delay(500);
            digitalWrite(ledpins[i], HIGH);
            Serial.print(ledpins[i]);
            Serial.print("inci led yandi");
        }
      delay(2000);
}
