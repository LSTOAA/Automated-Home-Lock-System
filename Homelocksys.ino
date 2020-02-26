/**
 * @Homelocksys.ino
 *
 * Automated Home Lock System using CP Plus Electric Door Lock, GSM SIM900A Module and Arduino Uno
 * Interfaced using Blynk
 * @version 0.1
 * @date 05-08-2019
 * @authors A. Sharma  and A. Saikia
 * @copyright Copyright (c) 2019 LSTOAA
 *
 */

char inchar; //Will hold the incoming character from the Serial Port.

 int led1 = 9;
 int led2 = 10;
 int led3 = 11;
 int led4 = 12;

 void setup()
 {
 // prepare the digital output pins
 pinMode(led1, OUTPUT);
 
 digitalWrite(led1, LOW);
 //Initialize GSM module serial port for communication.


 Serial.begin(9600);
 delay(3000); // give time for GSM module to register on network etc.
 Serial.println("AT+CMGF=1"); // set SMS mode to text
 delay(200);
 Serial.println("AT+CNMI=2,2,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 }
void SendMessage1()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919811172515\"\r");
  delay(1000);
  Serial.println("LOCK 1 OPEN");// The SMS text you want to send
  delay(100);
   Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
void SendMessage2()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919811172515\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("LOCK 1 CLOSE");// The SMS text you want to send
  delay(100);
   Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


void SendMessage5()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919811172515\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("LOCK 1 Not open");// The SMS text you want to send
  delay(100);
   Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void SendMessage6()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919811172515\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("LOCK 1 not closed");// The SMS text you want to send
 delay(100);
   Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 void loop() 
 {
 //If #a1b1c1d1 comes as sms, all led's should light up.
 if(Serial.available() >0)
 {
 inchar=Serial.read(); 
 if (inchar=='#')
   {
   delay(10);
   inchar=Serial.read(); 

 //first led
   if ((inchar=='L')||(inchar=='l'))
     {
   delay(10);
   inchar=Serial.read();

 if ((inchar=='o')||(inchar=='O'))
   {
   digitalWrite(led1, LOW);
   delay(10000);
   }
 else if ((inchar=='c')||(inchar=='C'))
   {
   digitalWrite(led1, HIGH);
   delay(10000);
   Serial.println("led");
   }
   delay(10);
     }
 Serial.println("AT+CMGD=1,4"); // delete all SMS
 }
 }}
