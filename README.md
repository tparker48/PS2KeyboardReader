# PS/2 Keyboard Reader

 - PS2KeyboardReader allows you to read the state of all keys of a PS/2 keyboard in real time.
 - Cloned and modified version of the PS2Keyboard library by Paul Stoffregen: https://github.com/PaulStoffregen/PS2Keyboard
   - **Note**: the original library is more suitable for use with PS/2 keyboards as standard keyboards, where the desired output is a string of characters. This library was made specifically for use in audio projects where multiple keys are pressed at once, and timing of key up/down events is important.

## Installation
 - Place this folder in the following location: `/home/{USERNAME}/.arduino15/packages/teensy/hardware/avr/x.x.x/libraries/`
 - Import as `#include "PS2KeyboardReader.h`
   - If you're not using the Arduino IDE, you may want to place it somewhere else.

## Usage
Example
```micropython
#include "PS2KeyboardReader.h"

// May be different depending on which pins you're using for you project
const int DataPin = 1;
const int IRQpin =  2;

PS2Keyboard keyboard;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);

  Serial.begin(9600);
}

void loop() {
  keyboard.refresh();

  // key_down() returns the current state of the key (true for down, false for up)
  if (keyboard.key_down(PS2_UPARROW)){
    Serial.print('The up key is currently being pressed!\n');
  }

  // key_toggle() will only return true when a key has been pressed and then released
  if (keyboard.key_toggle(PS2_DOWNARROW)){
    Serial.print('The down key was pressed and released!\n')
  }

  delay(5);
}
```
