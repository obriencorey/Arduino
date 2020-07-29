/*
 * By: Corey O'Brien
 * Purpose: This sketch is to display the current time on a single seven segment display,
 * much like the animal I am
 */

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "LNCMB";
const char *password = "4JZ8YSQH82J462P5";

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int A = 0;
int B = 14;
int C = 2;
int D = 13;
int E = 4;
int F = 5;
int G = 12;

int ONE = 15;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(ONE, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

    timeClient.begin();

}

/*
 * -=-=-=-=-=-=-=-=-=-=-=-=-=-
 *         main loop
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-
 */
void loop() {

  int   hour1 = 0;
  int   hour2 = 0;
  int   min1 = 0;
  int   min2 = 0;
  int   sec1 = 0;
  int   sec2 = 0;

  digitalWrite(ONE, HIGH);
  
  // put your main code here, to run repeatedly:
  timeClient.update();
  //Flash to indicate start of time
  
  if(timeClient.getHours() > 12){
    hour1 = (timeClient.getHours() - 5 - 12) / 10;
    hour2 = (timeClient.getHours() - 5 - 12) - hour1 * 10;
  }
  else{
    hour1 = (timeClient.getHours() - 5) / 10;
    hour2 = (timeClient.getHours() - 5) - hour1 * 10;     
  }
  min1 = (timeClient.getMinutes()) / 10;
  min2 = timeClient.getMinutes() - min1 * 10;
  sec1 = (timeClient.getSeconds()) / 10;
  sec2 = timeClient.getSeconds() - sec1 * 10; 

  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());

  Serial.print("hour1: ");
  Serial.println(hour1);
  Serial.print("hour2: ");
  Serial.println(hour2);
  Serial.print("min1: ");
  Serial.println(min1);
  Serial.print("min2: ");
  Serial.println(min2);
  Serial.print("sec1: ");
  Serial.println(sec1);
  Serial.print("sec2: ");
  Serial.println(sec2);

  spiral(200);
  displayClear();
  
  displayNum(hour1);
  delay(1000);
  displayClear();
  delay(100);
  
  displayNum(hour2);
  delay(1000);
  displayClear();
  delay(100);
  
  displayNum(min1);
  delay(1000);
  displayClear();
  delay(100);
  
  displayNum(min2);
  delay(1000);
  displayClear();
  delay(100);
  
  displayNum(sec1);
  delay(1000);
  displayClear();
  delay(100);
  
  displayNum(sec2);
  delay(1000);
  displayClear();
  delay(100);
}


void displayClear(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW); 
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
}

void displayNum(int num){
  switch (num){
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 4:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
  }
}

void spiral(int t){
  digitalWrite(A, HIGH);
  delay(t);
  digitalWrite(B, HIGH);
  delay(t);
  digitalWrite(C, HIGH);
  delay(t);
  digitalWrite(D, HIGH);
  delay(t);
  digitalWrite(E, HIGH);
  delay(t);
  digitalWrite(F, HIGH);
  delay(t);
  
  digitalWrite(A, LOW);
  delay(t);
  digitalWrite(B, LOW);
  delay(t);
  digitalWrite(C, LOW); 
  delay(t);           
  digitalWrite(D, LOW);
  delay(t);            
  digitalWrite(E, LOW);
  delay(t);
  digitalWrite(F, LOW);
  delay(t); 
}
