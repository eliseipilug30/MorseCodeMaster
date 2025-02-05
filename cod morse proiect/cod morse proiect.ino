#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int ledPin = A0;
int buzzerPin = 8;
int i = 0;

String myMessage = "1234";
String morseCode[] = {
  ".-" , "-...", "-.-.", "-..", ".", "..-.", "--.", 
  "....", "..", ".---", "-.-", ".-.." , "--", "-.",
  "---", ".--.", "--.-", ".-.", "...", "-", "..-",
  "...-", ".--", "-..-", "-.--", "--..",
  "-----", ".----", "..---", "...--", "....-", 
 ".....", "-....", "--...", "---.." ,"----."};
int ledBeep[] = {200, 500};
int value = 0;
int size = 0;
int codeSize = 0;
int buzzerSound = 10;
void setup()
{
 lcd.begin(16, 2);
 pinMode(ledPin, OUTPUT);
 //tone(buzzerPin, 10, 10000);

  while(myMessage[size] != '\0'){
    size++;
  }

}
void loop()
{
 
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print(myMessage);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  for(i = 0 ; i < size ; i++){
    if((int)myMessage[i] >= 97 && (int)myMessage[i] <= 122){
      codeSize = 0;
      value = (int)myMessage[i] - 32;
      lcd.print(morseCode[value - 65]);
      while(morseCode[value - 65][codeSize] != '\0'){
        codeSize++;
      }
      for(int j = 0 ; j < codeSize  ; j++){
        if(morseCode[value - 65][j] == '.'){
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 1000);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
          
        }
        else{
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 7500);
          delay(750);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
      }
    }
    else if (myMessage[i] == ' '){
      lcd.print("*spatiu*");
    }
    else if(myMessage[i] >= '0' && myMessage[i] <= '9'){
      codeSize = 0;
      value = (int)myMessage[i];
      lcd.print(morseCode[value - 22]);
      while(morseCode[value - 22][codeSize] != '\0'){
        codeSize++;
      }
      for(int j = 0 ; j < codeSize  ; j++){
        if(morseCode[value - 22][j] == '.'){
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 2000);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
        else{
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 7500);
          delay(750);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
      }
    }
    else{
      codeSize = 0;
      value = (int)myMessage[i];
      lcd.print(morseCode[value - 65]);
      while(morseCode[value - 65][codeSize] != '\0'){
        codeSize++;
      }
      for(int j = 0 ; j < codeSize  ; j++){
        if(morseCode[value - 65][j] == '.'){
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 2000);
          delay(200);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
        else{
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, buzzerSound, 7500);
          delay(750);
          digitalWrite(ledPin, LOW);
          delay(200);
        }
      }
    }
    delay(1500);
    lcd.clear();
    lcd.setCursor(0,0);
  }
  lcd.print("Done coding!");
  lcd.setCursor(0, 1);
  lcd.print("Restarting...");
  delay(3000);
}