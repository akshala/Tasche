#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int in_touch1 = 3;
//int in_touch2 = 4;
int count = 0;
const int n = 3;
//scl - A5
//sda - A4

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();  
  Serial.begin(9600);// initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  pinMode(in_touch1, INPUT);
}

void loop()
{
  lcd.setCursor(0,0);
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TASCHE");
  lcd.setCursor(1,1);
  lcd.print(". ");
  delay(1000);
  int value1 = digitalRead(in_touch1);
//  int value2 = digitalRead(in_touch2);
  Serial.println(value1 + " " + count);
//  delayMicroseconds(1000000);
//  lcd.clear();
  
  if(value1 == 1 && count == 0){
//    print(count)
    Serial.print("yes");
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Task" + String(count + 1));
    lcd.setCursor(1,1);
    lcd.print("IED");
    count = count + 1;
    if(count == n){
      count = 0;
    }
    delay(1000);
//    print(count);
  }
  else if(value1 == 1 && count == 1){
    Serial.print("yes");
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Task" + String(count + 1));
    lcd.setCursor(1,1);
    lcd.print("Maths");
    count = count + 1;
    if(count == n){
      count = 0;
    }
    delay(1000);
  }
  else if(value1 == 1 && count == 2){
    Serial.print("yes");
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Task" + String(count + 1));
    lcd.setCursor(1,1);
    lcd.print("Shopping");
    count = count + 1;
    if(count == n){
      count = 0;
    }
    delay(1000);
  }
  delay(1000);
  lcd.clear();
}
