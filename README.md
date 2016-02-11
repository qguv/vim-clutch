# vim-clutch
### where elitists go to die

what is it:

  - it's a hardware footpedal for (n)vim that goes into insert mode when you
    press it and returns to normal mode when you release it
  - so just press down to type real words in vim
  - literally the epitome of overengineering
  - I hate myself for writing it
  - like you'll never be able to type 'i' again
  - works regardless of keyboard layout

how to build it:

  - flash `vim-clutch.ino` to an Arduino Micro or another HID arduino-compatible microcontroller
  - connect a normally-open switch across digital pin 3 and ground
  - append `append_vimrc.txt` to your vimrc (for vim) or init.vim (for nvim)

how to use it:

  - depress the pedal to enter insert mode; release to return to normal mode
  - if you're already in insert mode (e.g. via `a`, `I`, `A`, `o`, `O`), you can (and should) press the pedal down so that you can type escape by releasing it once you're done
  - feel bad about the extent to which you find optimization necessary
  - did you really save any time?
