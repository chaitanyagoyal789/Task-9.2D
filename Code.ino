#include <GSM.h>
#define PINNUMBER ""

GSM gsmAccess;
GSM_SMS sms;

int led = 1;
int pir = 2;
int buzzer = 3;
int catchpin = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.println("SMS Messages Sender");
  // connection state
  bool notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) 
  {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) 
    {
      notConnected = false;
    } 
    
    else 
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
}

void loop()
{
  int remoteNum = 0452603505;
  char txtMsg[200] = "Rat has been trapped";
  if(digitalRead(5)== HIGH)
    {
      Serial.println("Object Detected");
      digitalWrite(1, HIGH);
      analogWrite(3, 200);
      digitalWrite(4, HIGH);
      sms.beginSMS(remoteNum);
      sms.print(txtMsg);
      sms.endSMS();
    } 
 else
  {
    Serial.println("No Object Detected");
    digitalWrite(1, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
   delay(1000);
}
