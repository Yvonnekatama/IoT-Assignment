#include <Servo.h>
Servo myServo;
int potpin=A1;
int Red = 2;
int Blue = 3;
int Green=4;
int val;
int trigpin=-9;
int echopin=8;
long distance;
long duration;

void setup()
{
myServo.attach(6);
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
void loop() {
  myServo.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,100);
  myServo.write(val);
  delay(15);
   
  if(distance <=20){
  digitalWrite(Red,HIGH);
  delay(3000);
  digitalWrite(Red, LOW);
  delay(3000);
   myServo.write(60);
  }
   else { myServo.write(0);}
  if (distance<=20){
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue,LOW);
  delay(3000);
   myServo.write(120);
 }
  else { myServo.write(0);}
   if (distance<=20){
  digitalWrite(Green,HIGH);
  delay(3000);
  digitalWrite(Green,LOW);
  delayMicroseconds(3000);
  myServo.write(180);
    }
  else{ myServo.write(0);}
}
void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance=duration*0.343/2;
}
 

/*Where Micro Servos are used
Automatic Door Openers.Supermarkets and hospital entrances are prime examples of automated door openers controlled by servo motors, whether the signal to open is via push plate beside the door for handicapped access or by radio transmitter positioned overhead.
Used in radio-controlled airplanes to position control surfaces like elevators, rudders, walking a robot, or operating grippers.
Conveyor Belts.Servo motors move, stop, and start conveyor belts carrying product along to various stages,example, in product packaging or bottling, and labeling.*/













