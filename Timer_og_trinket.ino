#include <TinyWireM.h>
#include <LiquidCrystal_I2C.h>
#include <BigNums2x2.h>

int C = 9; // count ones seconds
int S = 5; // ount tens seconds
int M = 59; // count minutes
int H = 23; // count hours
//initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address
BigNums2x2 bigNum(TREK);

void setup()
{

  lcd.begin(16, 2); //set up the LCD's number of columns and rows
  lcd.setCursor(2,0);
  lcd.print("ESCAPE  FROM");
  lcd.setCursor(4,1);
  lcd.print("NEW YORK");

  delay(5000);
  lcd.clear();

  
}
void loop()
{
  bigNum.font(2);
  lcd.setCursor(11, 0);
  lcd.print((char)165);
  lcd.setCursor(11, 1);
  lcd.print((char)165);
  lcd.setCursor(5, 0);
  lcd.print((char)165);
  lcd.setCursor(5, 1);
  lcd.print((char)165);
  /*  lcd.setCursor(1, 0);
    lcd.print ("ESCAPE NEW YORK");
    lcd.setCursor(6, 1);
    bigNum.print(":");
    lcd.setCursor(9, 1);
    lcd.print(":");
  */

  C--;
  delay(1000);

  if (C < 0)
  {
    S--;
    C = 9;
  }
  if (S < 0)
  {
    M--;
    S = 5;
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
    bigNum.print(M, 2, 6, ' ');
                 //lcd.print(M);
  }
  else
  {
    //lcd.setCursor(6, 1);
    bigNum.print(0, 1, 7, ' ');
    //lcd.setCursor(8, 1);
    bigNum.print(M, 1, 8, ' ');
    //lcd.setCursor(11, 0);
    //lcd.print(".");
    //lcd.setCursor(11, 1);
    //lcd.print(".");
  }
  
  //if (S > 9)
  {
    //lcd.setCursor(14,0);
    bigNum.print(S, 1, 12, ' ');
    //lcd.print(S);
  }
  //else
  {
    //lcd.setCursor(14, 0);
    //lcd.print(0);
    //bigNum.print(0, 1, 12, ' ');
    //lcd.setCursor(15, 0);
    //lcd.print(S);
    bigNum.print(C, 1, 14, ' ');
    //lcd.setCursor(12, 1);
    //lcd.print(" ");
  }
  
    if (H > 9)
    {
      //lcd.setCursor(1, 0);
      bigNum.print (H, 2, 0, ' ');
    }
    else
    {
      //lcd.setCursor(4, 1);
      bigNum.print(0, 1, 0, ' ');
      //lcd.setCursor(5, 1);
      bigNum.print(H, 1, 3, ' ');
      //lcd.setCursor(6, 1);
      //bigNum.print("%");
    }
}
