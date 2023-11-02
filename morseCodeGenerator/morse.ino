#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

static const struct { char letter, *code; }
MorseMap[] =
{
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', "-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { ' ', " " }, //Gap between word, seven units
  { '1', ".----" },
  { '2', "..---" },
  { '3', "...--" },
  { '4', "....-" },
  { '5', "....." },
  { '6', "-...." },
  { '7', "--..." },
  { '8', "---.." },
  { '9', "----." },
  { '0', "-----" },
  { '.', "·–·–·–" },
  { ',', "--..--" },
  { '?', "..--.." },
  { '!', "-.-.--" },
  { ':', "---..." },
  { ';', "-.-.-." },
  { '(', "-.--." },
  { ')', "-.--.-" }
};


void setup() {
  pinMode(1, OUTPUT);
  delay(1000);
  digitalWrite(1,HIGH);
  delay(1000);
  digitalWrite(1, LOW);
}


void convertToMorse(const char* msg, char output[1000], size_t sizeOutput){
    output[0] = '\0';
    char* morseCode;

    for(size_t i=0; i<strlen(msg); i++){
        char c = toupper(msg[i]);
        if(c == ' '){
            morseCode = " ";
        }else{
            morseCode = NULL;
            for(size_t j=0; j< sizeof(MorseMap) / sizeof(MorseMap[0]); j++){
                if(MorseMap[j].letter == c){
                    morseCode = MorseMap[j].code;
                    break;
                }
            }
            if(morseCode == NULL) morseCode = "";
        }
        strncat(output, morseCode, sizeOutput - strlen(output)-1);
    }
}

void play(const char morse[1000]){
  for(int i=0; morse[i] != '\0'; i++){
    
    switch(morse[i]){
      case '.':
        digitalWrite(1, HIGH);
        delay(200);
        digitalWrite(1, LOW);
        delay(1000);
        break;
      case '-':
        digitalWrite(1, HIGH);
        delay(600);
        digitalWrite(1, LOW);
        delay(1000);
        break;
      case ' ':
        delay(400);
        delay(1000);
        break;
    }
  }
  return;
}

void loop() {
  delay(2000);
  char morseOutput[1000];
  const char* input = "HELLO WORLD";

  convertToMorse(input, morseOutput, sizeof(morseOutput));
  for (int i = 0; morseOutput[i] != '\0'; i++) {
    play(&morseOutput[i]); // Transmit each letter
    delay(600); // Delay between letters
  }
}
