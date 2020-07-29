/*
 * By:        Corey O'Brien
 * Created:   18 May 2020
 * Purpose:   Control 7-seg with ESP8266
 * 
 * Added 21 MAY 2020
 *      Working with four digit display
 */
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

void loop() {
  
  for(int i = 0; i<10; i++){
    digitalWrite(ONE,HIGH);
    displayNum(i);
    delay(10);
    displayClear();
    digitalWrite(ONE,LOW);
    delay(10);


    i++;

    digitalWrite(TWO,HIGH);
    displayNum(i);
    delay(10);
    displayClear();
    digitalWrite(TWO,LOW);
    delay(10);

     i++;

    digitalWrite(THREE,HIGH);
    displayNum(i);
    delay(10);
    displayClear();
    digitalWrite(THREE,LOW);
    delay(10);
    
  }
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
