#include <Wire.h>
//#include <BigNums2x2.h>
#include <LiquidCrystal_I2C.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int S = 59; // count seconds
int M = 59; // count minutes
int H = 23; // count hours
//initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3f, 16, POSITIVE);
//BigNums2x2 bigNum(SERIF);

void setup()
{
  lcd.begin(16, 2); //set up the LCD's number of columns and rows
}
void loop()
{
  lcd.setCursor(1, 0);
  lcd.print ("Escape New York");
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(9, 1);
  lcd.print(":");

  S--;
  delay(5000);

  if (S < 0)
  {
    M--;
    S = 59;
  }
  if (M < 0)
  {
    H--;
    M = 59;
  }
  if (H < 0) {
    H = 23;
    M = 59;
    S = 59;
  } if (M > 9)
  {
    lcd.setCursor(6, 0);
    lcd.print(M);
  }
  else
  {
    lcd.setCursor(6, 0);
    lcd.print("0");
    lcd.setCursor(8, 0);
    lcd.print(M);
    lcd.setCursor(10, 0);
    lcd.print(":");
/*   lcd.setCursor(6, 0);
    bigNum.print("0");
    lcd.setCursor(8, 0);
    bigNum.print(M);
    lcd.setCursor(10, 0);
    bigNum.print(":");
*/
  }

  if (S > 9)
  {
    lcd.setCursor(12, 0);
    lcd.print(S);
    /*
    lcd.setCursor(12, 0);
    bigNum.print(S);
    */
  }
  else
  {
    lcd.setCursor(12, 0);
    lcd.print(S);
/*    lcd.setCursor(12, 0);
    bigNum.print("0");
    lcd.setCursor(14, 0);
    bigNum.print(S);
*/
  }

  if (H > 9)
  {
    lcd.setCursor(1, 0);
    lcd.print (H);
/*    lcd.setCursor(1, 0);
    bigNum.print (H); 
*/
  }
  else
  {
    lcd.setCursor(1, 0);
    lcd.print("0");
    lcd.setCursor(2, 0);
    lcd.print(H);
    lcd.setCursor(4, 0);
    lcd.print(":");
/*
    lcd.setCursor(1, 0);
    bigNum.print("0");
    lcd.setCursor(2, 0);
    bigNum.print(H);
    lcd.setCursor(4, 0);
    bigNum.print(":");
*/    
  }
}
