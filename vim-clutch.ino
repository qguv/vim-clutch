/*

vim-clutch.ino: a hardware pedal for hyperoptimized vi-style text editing

run it on an Arduino-compatible board with HID support, e.g.

  - Arduino/Genuino Micro and other 32u4-based boards
  - Arduino/Genuino Due
  - Arduino/Genuino Zero

*/

#include <Bounce2.h>
#define INPUT_PIN 3

Bounce bouncer = Bounce();
bool was_pressed, is_pressed = false;

void setup() {
  pinMode(INPUT_PIN, INPUT_PULLUP);
  bouncer.attach(INPUT_PIN);
  bouncer.interval(5); // milliseconds
  Keyboard.begin();
}

void loop() {
  bouncer.update();
  was_pressed = is_pressed;
  is_pressed = !bouncer.read();

  if (is_pressed != was_pressed) {
    if (is_pressed) {
      Keyboard.write(KEY_F6);
    } else {
     Keyboard.write(KEY_ESC);
    }
  }
}

/* vi: set et sw=2 sts=2: */
