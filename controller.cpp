#include <Servo.h> 
Servo servo1; 
Servo servo2; 
int lightValue1; 
int lightValue2; 
int lightValue3; 
int lightValue4; 
int servoMove = 90; 
int servoMove2 = 90; 
int SERVO_THRESHOLD = 50; 
int SERVO_PIN_1 = 9; 
int SERVO_PIN_2 = 11; 
int DELAY_NUM = 10; 
int SERVO_MIN = 0; 
int SERVO_MAX = 180; 
void setup() 
{ 
servo1.attach(SERVO_PIN_1); 
servo2.attach(SERVO_PIN_2); 
Serial.begin(9600); 
} 
void loop() 
{ 
servo1.write(servoMove); 
servo2.write(servoMove2); 
if ((lightValue1 + lightValue3) - (lightValue2 + lightValue4) > SERVO_THRESHOLD) { 
servoMove--; 
} 
if ((lightValue2 + lightValue4) - (lightValue1 + lightValue3) > SERVO_THRESHOLD) { 
servoMove++; 
} 
if ((lightValue1 + lightValue4) - (lightValue2 + lightValue3) > SERVO_THRESHOLD) { 
servoMove2++; 
  } 
  
  if ((lightValue2 + lightValue3) - (lightValue1 + lightValue4) > SERVO_THRESHOLD) { 
    servoMove2--; 
  } 
  if (servoMove2 > SERVO_MAX) { 
    servoMove2--; 
  } 
  if (servoMove2 < SERVO_MIN) { 
    servoMove2++; 
  } 
  if (servoMove > SERVO_MAX) { 
    servoMove--; 
  } 
  if (servoMove < SERVO_MIN) { 
    servoMove++; 
  }   
   
 
  delay(DELAY_NUM);   
 
} 
 
/* Prints photoresistor values for debugging
  lightValue1 = analogRead(A0); 
  lightValue1 = map(lightValue1, 300, 650, 0, 180); 
  Serial.print("lightValue1 : "); 
  Serial.println(analogRead(A0)); 
  lightValue2 = analogRead(A1); 
  lightValue2 = map(lightValue2, 300, 650, 0, 180); 
  Serial.print("lightValue2 : "); 
  Serial.println(analogRead(A1)); 
  lightValue3 = analogRead(A2); 
  lightValue3 = map(lightValue3, 300, 650, 0, 180); 
  Serial.print("lightValue3 : "); 
  Serial.println(analogRead(A2)); 
  lightValue4 = analogRead(A3); 
  lightValue4 = map(lightValue4, 300, 650, 0, 180); 
  Serial.print("lightValue4 : "); 
  Serial.println(analogRead(A3)); 
*/ 