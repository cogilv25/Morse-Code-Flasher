#include "MorseCode.h"
//just a pointer example but doesn't need to be one
MorseCodeWriter * morseOutput;
int pin = 7;
void setup() {
  //Initialise the pointer
  morseOutput = new MorseCodeWriter(pin,2);
  pinMode(pin,OUTPUT);
}

void loop() {
  //You use -> instead of . when using a pointer
  morseOutput->writeSentenceInMorse("sos");
  delay(1400);
}
