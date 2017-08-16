#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo s2;
Servo s3;
Servo s4;
Servo s5;
// twelve servo objects can be created on most boards
int letters[27][5]{
  //a
  {180,180,180,180,0},
  //b
  {0,0,0,0,180},
  //c
  {90,90,90,90,90},       
  //d
  {180,180,180,0,180},
  //e
  {180,180,180,180,180},
  //f
  {0,0,0,180,90},
  //g
  {180,180,180,0,0},
  //h
  {180,180,0,0,180},
  //i
  {0,180,180,180,90},
  //j
  {90,0,0,0,90},
  //k
  {180,180,0,0,0},
  //l
  {180,180,180,0,0},
  //m
  {180,90,90,90,180},
  //n
  {180,180,90,90,180},
  //o
  {90,90,90,90,130},
  //p
  {180,180,90,0,0},
  //q
  {180,180,180,90,90},
  //r
  {180,180,0,10,90},
  //s
  {180,180,180,180,90},
  //t
  {180,180,180,50,90},
  //u
  {180,180,0,0,50},
  //v
  {180,180,10,10,50},
  //w
  {180,0,0,0,50},
  //x
  {180,180,180,50,180},
  //y
  {0,180,180,180,0},
  //z
  {180,180,180,0,0},
  //nothing
  {180,180,180,180,180}
};
int number;
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  
  
}




void loop() {
  
  if (Serial.available() > 0){
    
    String string = Serial.readString();
    number = string.toInt();
    callletter(number);
    delay(1000);
  }
}
void callletter(int letter){
  
    letter = letter - 1;
    Serial.println(letter);
    Serial.end();
    myservo.attach(9,0,letters[letter][0]);  // attaches the servo on pin 9 to the servo object
    s2.attach(11,0,letters[letter][1]);
    s3.attach(10,0,letters[letter][2]);
    s4.attach(6,0,letters[letter][3]);
    s5.attach(5,0,letters[letter][4]);
    for (pos = 0; pos <= letters[letter][0]; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);
      
    }
    for (pos = 0; pos <= letters[letter][1]; pos += 1) { // goes from 0 degrees to 180 degrees
      s2.write(pos);
    }
    for (pos = 0; pos <= letters[letter][2]; pos += 1) { // goes from 0 degrees to 180 degrees
      s3.write(pos);
    }
    for (pos = 0; pos <= letters[letter][3]; pos += 1) { // goes from 0 degrees to 180 degrees
      s4.write(pos);
    }
    for (pos = 0; pos <= letters[letter][4]; pos += 1) { // goes from 0 degrees to 180 degrees
      s5.write(pos);
    }
    delay(100);
    myservo.detach();  // attaches the servo on pin 9 to the servo object
    s2.detach();
    s3.detach();
    s4.detach();
    s5.detach();
    Serial.begin(9600);
}

