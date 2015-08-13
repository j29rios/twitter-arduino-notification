/* 
Author: Prasanna Venkadesh
Modified by: Jorge Rios (@j29rios)
License: Free Software (GPL V3)

Listens for data over serial connection and
show a tweet on Liquid Crystal Display (LCD)
*/

//Include LCD library
#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#ifndef SERIAL_RATE
#define SERIAL_RATE     115200
#endif

#ifndef SERIAL_TIMEOUT
#define SERIAL_TIMEOUT  5
#endif

String out = "";
char in;

void setup() {
  Serial.begin(SERIAL_RATE);
  Serial.setTimeout(SERIAL_TIMEOUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

  
void loop() {
  out = "";
  while (Serial.available() > 0) {
    lcd.clear();
    in =  Serial.read();
    out.concat(in);
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if (out != "") {
    /*   lcd.setCursor(0, 1); /*0,1 : second line*/
    //Print a message to first line of LCD
    lcd.print(out);
  }
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(400);
  }  
}
