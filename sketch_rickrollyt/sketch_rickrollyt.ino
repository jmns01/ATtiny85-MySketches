#include <DigiKeyboard.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Open run windows
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("chrome https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  DigiKeyboard.delay(1000);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
