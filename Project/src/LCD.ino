#include<Wire.h>
#include<LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x3F,16,2);
LiquidCrystal_I2C lcd(0x3F,16,4);

void setup() {
  // put your setup code here, to run once:
 
 //Lap binh thuong
 // lcd.begin(16,2); //Vi kich thuoc LCD là 16x2
 // lcd.print("hello"); //mac dinh in tu dong so 1
 // lcd.setCursor(0,1); //in tu dong thu 2 thi xac dinh toa do truoc
 // lcd.print("hihihi"); //noi dung print o dong thu 2

  //Lap I2C
  lcd.init();
  lcd.begin(16,4);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("adruino 360");

}

void loop() {
 
}
