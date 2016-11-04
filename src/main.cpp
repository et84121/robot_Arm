#include "Arduino.h"
#include <Servo.h>

Servo myServo[3];

void setup(/* arguments */) {
  Serial.begin(9600);
  int servo_pin[] ={3,5,6};
  for (int i = 0; i < sizeof(servo_pin)/sizeof(servo_pin[0]); i++) {
    myServo[i].attach(servo_pin[i]);
  }

  Serial.println("input '<servo_pin> <degree>'");
}

void loop(){
  for(int a=0;a<3;a++){
    int val = analogRead(a);
    val = map(val, 0, 1023, 0, 180);
    myServo[a].write(val);
    Serial.println("Servo "+ (String)a + " success rotate to degree "+ (String)val);
  }
  if(Serial.available()!=0){
    String control_text = Serial.readString();
    Serial.println(control_text);
    int servo_num = control_text.substring(0,1).toInt();
    int degree = control_text.substring(2).toInt();
    myServo[servo_num].write(degree);
    String success_info = "Servo "+ (String)servo_num + " success rotate to degree "+ (String)degree;
    Serial.println(success_info);
    delay(50);
  }
}
