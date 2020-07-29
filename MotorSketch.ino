/*
 * By corey obrien
 * started on may 9th 2020
 * 
 * important info
 *      motor A is the right motor
 *      motor B is the left motor
 * 
 * updates:
 *      8:13 may 9th - added ir control and created functions to set the direction
 *                     of the motors, as well as their speed
 *                     Since they are cheap they require different pwms to get the same
 *                     speed, so there is a motor speed offset
 *                     
 *                     as of now, the program allows for the four arrow keys and the ok
 *                     button of the ir remote to act as control
 *   12:38 may 10th  - added comments on functions and refined the motor control direction
 */
#include <IRremote.h>

#define IR_UP     0xFF629D    //These values are the respective IR codes for each button
#define IR_DOWN   0xFFA857
#define IR_LEFT   0xFF22DD
#define IR_RIGHT  0xFFC23D
#define IR_STOP   0xFF02FD    //This code is for the ok button

int RECV_PIN = 12;            //Pin for the ir receiver

const int IN1 = 2;             //These four values are the arduino pins for the
const int IN2 = 4;             //logical inputs of the hbridge
const int IN3 = 7;             //they control direction of the motor
const int IN4 = 8;

const int MOTORA = 5;         //These are the pins for the outputs of the hbridge
const int MOTORB = 6;         //in this case there are two, A and B

IRrecv irrecv(RECV_PIN);
decode_results results;

int motorSpeed_Right = 100;   //motor speed for motor A
int mototSpeed_Left = motorSpeed_Right - 20;    //Offset because cheap motors :(

void setup() {

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);

  for (int i = 5; i <11; i++)
  {
    pinMode(i, OUTPUT);  
  }

}

void loop() {
  
  //setMSpeed(MOTORA, motorSpeed);
  //setMSpeed(MOTORB, motorSpeed);

  if(irrecv.decode(&results)){
     switch(results.value){
      
      case IR_UP:
      Serial.println("Up");                   // if the ir sensor receives up
      setDirection("F");                      //Set the motor direction to forward
      setMSpeed(MOTORA, motorSpeed_Right);          //set each motor speed
      setMSpeed(MOTORB, mototSpeed_Left);
      break;
      
      case IR_DOWN:
      Serial.println("Down");
      setDirection("B");                      //Set the motor direction to backward
      setMSpeed(MOTORA, motorSpeed_Right);
      setMSpeed(MOTORB, mototSpeed_Left);
      break;
      
      case IR_RIGHT:
      Serial.println("Right");
      setDirection("R");                      //set the motor direction to right
      setMSpeed(MOTORA, motorSpeed_Right);  
      setMSpeed(MOTORB, mototSpeed_Left);
      break;
      
      case IR_LEFT:
      Serial.println("Left");
      setDirection("L");                      //set the motor direction to left
      setMSpeed(MOTORA, motorSpeed_Right);  
      setMSpeed(MOTORB, mototSpeed_Left);
      break;
      
      case IR_STOP:
      Serial.println("Stop");
      setMSpeed(MOTORA, 0);
      setMSpeed(MOTORB, 0);
      break;

     }
     irrecv.resume();
  }
  

}



void setDirection(char str[])
{
  /*
  This function sets the direction of rotation by changing
  the values of the h bridge motor driver orientation is 
  relative to the side opposite of the motor wires/with the screws

  there are four pins for the logic and four possible inputs
  for each pin
  LHLW
  HLHL
  LHHL
  HLLH

  char str[] - the argument string
  
  ||possible arguments||
  F - forward
  B - reverse
  R - right
  L - left
  */
  
  if(str == "F"){
   //These values change the appropriate switches to make the motor rotate
   //clockwise
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);  
   digitalWrite(IN3,LOW);  
   digitalWrite(IN4,HIGH);  
  }
  else if (str == "B"){
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);   
  }
  else if(str == "L"){
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW); 
  }
  else{
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH); 
    
  }
  
  
}

void setMSpeed(int motor, int mspeed)
{
  /*
   * This functino writes a PWM to the motor which determines its speed 
   * int motor - the pin number of the motor 
   * int mspeed - the value of the PWM signal, for the tt motors this can be 70-255
   */
  
  analogWrite(motor,mspeed);
}
