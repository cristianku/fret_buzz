
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const fret_buzz_pin = 5;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //need this text to work

pinMode(fret_buzz_pin, INPUT_PULLUP);

int time_prev = 0;

boolean read_fret_buzz_pin(){
   int read =  digitalRead (fret_buzz_pin);

   if ( read == 1){
     return false;
   } else {
     return true;
   }  

}



void setup() {
  // Serial.begin(9600);
{
  // initialize the LCD
   lcd.begin(16,2);

  // Turn on the blacklight and print a message.
   lcd.backlight();
 
}
}

void loop() {
  if read_fret_buzz_pin(){
    time_prev = millis();
    // fret buzz on the screen will stay for a while
    lcd.setCursor(0,0);
    lcd.print("FRET_BUZZ"); 
  }
   
  if (millis() - time_prev > 1000){
    // reset the screen 
    lcd.setCursor(0,0);
    lcd.print(".");
  } 
  delay(100);

}

 
  
