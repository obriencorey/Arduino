/*
 * By:        Corey O'Brien
 * Created:   21 May 2020
 * Purpose:   Control 4 digit 7-seg with ESP8266 and display fib numbers
 * 
 * 
 */

//pins for each section of the 7segment display
int A = 0;
int B = 14;
int C = 2;
int D = 13;
int E = 4;
int F = 5;
int G = 12;

//trigger pins
int ONE = 15;
int TWO = 16;
int THREE = 10;

void setup() {                
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(THREE, OUTPUT);
  
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
  digitalWrite(G, HIGH);
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
  digitalWrite(G, LOW);
  delay(t); 
}

void displayThree(int num, int delaytime, int displaytime) {
  /*
   * By Corey O'Brien
   * This function uses three arguments
   * int num - this is the 3 digit number to be displayed
   * int delaytime - this is the delay time BETWEEN DIGITS (For debugging)
   * int displaytime - this is the amount of time the number should be displayed for
   */
  int hundreds = num / 100;
  int tens = (num - 100* (num / 100)) / 10;
  int ones = num - tens * 10 - hundreds * 100; 
  int counter1 = 0;

  
  int delaytimeTotal = 3 * delaytime;

  int timetocount = displaytime / (delaytimeTotal + 1);

  while(counter1 < timetocount){
  
  digitalWrite(ONE,HIGH);
  displayNum(hundreds);
  delay(delaytime);
  displayClear();
  digitalWrite(ONE,LOW);
  
  digitalWrite(TWO,HIGH);
  displayNum(tens);
  delay(delaytime);
  displayClear();
  digitalWrite(TWO,LOW);
  
  digitalWrite(THREE,HIGH);
  displayNum(ones);
  delay(delaytime);
  displayClear();
  digitalWrite(THREE,LOW);

  delay(1); //this is to keep track of how long the number has been displayed for

  counter1++;
  }
}

void loop() {

  int prev1 = 1;
  int prev2 = 1;
  int temp;

  
  
  for(int i = 1; i < 999;){
    
    temp = i;
    i = prev1 + prev2;
    prev2 = prev1;
    prev1 = i;
    
    displayThree(i,1,800);
  }

  

  
  
    
}
