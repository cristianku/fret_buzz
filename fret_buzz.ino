
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// const fret_buzz_pin = 5;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //need this text to work


int time_prev = 0;

boolean read_fret_buzz_pin(int x){
   int read =  digitalRead (x);

   if ( read == 1){
     return false;
   } else {
     return true;
   }  

}



void setup() {
  // Serial.begin(9600);

  pinMode(5, INPUT_PULLUP);
  pinMode(2,OUTPUT); //buzzer connesso al pin 2

  // initialize the LCD
   lcd.begin(16,2);

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(".");
  // lcd.clear(); 
 
}

void loop() {
  if (read_fret_buzz_pin(5) && time_prev == 0 ){
    time_prev = millis();
    // fret buzz on the screen will stay for a while
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("FRET_BUZZ"); 
    tone(2, 1000, 500); //suona una nota alla frequenza di 1000Hz per la durata di 500 ms
// delay(1500); //attende 1500 ms
// tone(2, 1000, 500);
// delay(1500);
// tone(2, 1000, 2000); //suona una nota alla frequenza di 1000Hz per la durata di 2 secondi
// delay(2000); //attende 2 secondi
  }
   
  if ((millis() - time_prev > 5000) && (time_prev > 0)  ){
    // reset the screen 
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print(".");
    time_prev = 0;
  } 
  delay(100);
  // lcd.clear(); 

}

 
 // buzzer
//  void setup()
// {
// pinMode(2,OUTPUT); //buzzer connesso al pin 2
// }
// void loop()
// {
// tone(2, 1000, 500); //suona una nota alla frequenza di 1000Hz per la durata di 500 ms
// delay(1500); //attende 1500 ms
// tone(2, 1000, 500);
// delay(1500);
// tone(2, 1000, 2000); //suona una nota alla frequenza di 1000Hz per la durata di 2 secondi
// delay(2000); //attende 2 secondi
// }


  
