//#include <LiquidCrystal_I2C_Hangul.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(6,7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(2,INPUT); //touch 1
  pinMode(3,INPUT); //touch 2

}

void loop() {
  // put your main code here, to run repeatedly:
  int value1=digitalRead(2);
  int value2=digitalRead(3);
  int ans=0;
  if (value1==1 && value2==0){
    mySerial.print(String(1));
    mySerial.print(",");
    Serial.println(1);
    //break;
  }
  else if (value1==0 && value2==1){
    mySerial.print(String(2));
    mySerial.print(",");
    Serial.println(2);
    //break;
  }
}
