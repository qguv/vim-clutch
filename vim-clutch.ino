/*
vim-clutch: where elitists go to die

what is it:

  - it's a hardware footpedal for (n)vim that goes into insert mode when you
    press it and returns to normal mode when you release it
  - so just press down to type real words in vim
  - literally the epitome of overengineering
  - I hate myself for writing it
  - like you'll never be able to type 'i' again
  - works regardless of keyboard layout

how to build it:

  - flash this to an arduino micro
  - append "append_vimrc.txt" to your vimrc (for vim) or init.vim (for nvim)
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
