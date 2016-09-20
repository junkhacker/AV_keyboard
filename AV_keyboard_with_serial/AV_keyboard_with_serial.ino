#include "Keyboard.h"

int bereit = 0;
int zeichen = 0;

int inputState[7];
int lastInputState[7];

const int inputPin[] = {9, 8, 7, 10, 16, 14, 15};

void setup() {
  // set up the variables for digital inputs
  for (int i = 0; i < 7; i++) { //set initial values of state variables
    inputState[i], HIGH;
    lastInputState[i], LOW;
  }
  //digital inputs array set and pulled high
  for (int i = 0; i < 7; i++) {
    pinMode(inputPin[i], INPUT_PULLUP);
  }

  // open the serial port:
  Serial1.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  while (Serial1.available()) {
    bereit = (char)Serial1.read();
  }
  delay(100);

  for (int i = 0; i < 7; i++) {
    inputState[i] = digitalRead(inputPin[i]);
    if (inputState[i] != lastInputState[i]) { // if a change is detected ...
      if (inputState[i] == LOW ) { // and is currently pulled low...
        switch (i) {
          case 0:
            bereit = 'A';
            break;
          case 1:
            bereit = 'B';
            break;
          case 2:
            bereit = 'C';
            break;
          case 3:
            bereit = 'D';
            break;
          case 4:
            bereit = 'E';
            break;
          case 5:
            bereit = 'F';
            break;
          case 6:
            bereit = 'G';
            break;
        }
      }
    }
    lastInputState[i] = inputState[i];
  }
  switch (bereit) {
    case 'A':
      zeichen = 251;
      break;
    case 'B':
      zeichen = 250;
      break;
    case 'C':
      zeichen = 249;
      break;
    case 'D':
      zeichen = 248;
      break;
    case 'E':
      zeichen = 247;
      break;
    case 'F':
      zeichen = 246;
      break;
    case 'G':
      zeichen = 245;
      break;
    case 'H':
      zeichen = 244;
      break;
    case 'I':
      zeichen = 243;
      break;
    case 'J':
      zeichen = 242;
      break;
  }
  if (zeichen != 0) {
    Keyboard.press(zeichen);
    Keyboard.release(zeichen);
  }
  bereit = 0;
  zeichen = 0;
}

/*
    
*/

