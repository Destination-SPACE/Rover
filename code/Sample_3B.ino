//
//
//          This code makes the robot drive forward for 1 second and then stop
//
//
//////////////////////////////////////////////////////////////////////////////

//Left Motor Names and Locations
const int ENA = 5;     //ENA on the motor driver is wired to D5 on the Nano
const int IN1 = 6;    //IN1 on the motor driver is wired to D6 on the Nano
const int IN2 = 7;    //IN2 on the motor driver is wired to D7 on the Nano

//Right Motor Names and Locations
const int IN3 = 8;    //IN3 on the motor driver is wired to D8 on the Nano
const int IN4 = 9;    //IN4 on the motor driver is wired to D9 on the Nano
const int ENB = 10;   //ENB on the motor driver is wiered to D10 on the Nano

//Ultrasonic Names and Locations
int trig = 3; 
int echo = 4; 
long lecture_echo; 
long cm;

//////////////////////////////////////////////////////////////////////////////

void setup() 

{  
//// motor driver setup ////
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENB,OUTPUT);
//// motor engage ////
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
//// ultrasonic setup ////
pinMode(trig, OUTPUT); 
digitalWrite(trig, LOW); 
pinMode(echo, INPUT); 
//// serial engage ////
Serial.begin(9600); 
}

//////////////////////////////////////////////////////////////////////////////

void loop() 
{


    digitalWrite(trig, HIGH);              ///////////////////////////////////
    delayMicroseconds(10);                 ///////////////////////////////////
    digitalWrite(trig, LOW);               //// Find distance and record /////
    lecture_echo = pulseIn(echo, HIGH);    ///////////////////////////////////
    cm = lecture_echo / 58;                ///////////////////////////////////
    Serial.print ("Distance in cm:");      //print distance to serial monitor
    Serial.println (cm);

if (cm < 12)
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay (1000);
  
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);   
    analogWrite(ENA, 120); //left wheel spins at this speed
    analogWrite(ENB, 120); //right wheel spiins at this speed
    delay (450); //this changes how long it spins
    
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay (1000);
}
else
{
  digitalWrite(IN1,HIGH);     //Swap "HIGH" and "LOW" in IN1 and IN2 to change left wheel direction
  digitalWrite(IN2,LOW);      
  digitalWrite(IN3,HIGH);     //Swap "HIGH" and "LOW" in IN1 and IN2 to change right wheel direction
  digitalWrite(IN4,LOW);      

  analogWrite(ENA, 120); //0-255   Rotation Speed Left Wheel
  analogWrite(ENB, 120); //0-255   Rotation Speed Right Wheel  
}
}
