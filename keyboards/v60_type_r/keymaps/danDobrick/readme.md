KB Paradise V60 Type R Customized keymap by DanDobrick
======================
Custom keymap specifically for the Polestar Type R (with both backlight and underglow)

HUGE thanks to [FollowingGhosts](https://github.com/BenRLewis) since a lot of this keymapping is based on his work.

# Keymap Notes
Modified version of the keymap on layer 0 and highly modified version of layer 1.

Supports Underglow lighting with RGB modifier keys and normal backlight.

The Capslock light turns on whenever layer 1 is active to prevent accidental keypresses.

Underglow color corresponds to layer:
* Light teal = layer 1
* Light green = layer 2
* Red = control layer 3

## Leader keys
---------------------

`LEADER` -> CMD = Switch to CTRL layer

# Keymaps

(Un-labeled keys are transparent)
```
  Keymap 0: Default Layer (Qwerty)
  * CAPS opens Layer 1 if held and triggers ESC when tapped.\
  * Hold Tab for MEH (Left Control, Shift and Alt)
  * Fn toggles layer 1 on/off.
  * Esc remapped to `.
  * Double tap LShift for capslock
  ,-------------------------------------------------------------.
  |   ` |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
  |-------------------------------------------------------------|
  |Tab/Meh|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
  |-------------------------------------------------------------|
  |LT(1,Esc)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
  |-------------------------------------------------------------|
  |LShift    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
  |-------------------------------------------------------------|
  |Ctrl|Alt |Gui |          Space           |TG1 |Gui |LEAD|Ctrl|
  `-------------------------------------------------------------'

  Keymap 2: FN Layer
  * Arrow keys are like vim but shifted by one (jkl;)
  * Pause is mapped to media pause and previous/skip abut it.
  ,-----------------------------------------------------------.
  |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
  |-----------------------------------------------------------|
  |    |   |   |   |   |   |   |   |   |Prv|Pau|Nxt|   |      |
  |-----------------------------------------------------------|
  |      |C<-|   |C->|   |   |   |Up |Dwn|Lft|Rgt|   |        |
  |-----------------------------------------------------------|
  |        |   |   |   |   |Vld|Vlu|Mut|   |   |   |          |
  |-----------------------------------------------------------|
  |    |    |    |                        |TG0 |   |     |    |
  `-----------------------------------------------------------'

  Keymap 3: CTRL Layer (ONLY ACCESSIBLE VIA LEADER -> 'CMD')
  * Backlight/Underglow keys are all the same as the printed keys.
  ,-----------------------------------------------------------.
  |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
  |-----------------------------------------------------------|
  |      |   |   |RGB|HUI|SAI|VAI|   |   |   |   |   |   |    |
  |-----------------------------------------------------------|
  |      |   |   |   |HUD|SAD|VAD|   |   |   |   |   |        |
  |-----------------------------------------------------------|
  |        |BLD|BLT|BLI|   |   |   |   |   |   |   |          |
  |-----------------------------------------------------------|
  |    |    |    |                        |TG0 |   |RESET|    |
  `-----------------------------------------------------------'
```
## Build
To build this keymap, simply run `make v60_type_r:danDobrick`.


## TODO:
* Allow backlight to be saved to EEPROM via CMD layer for each other layer.
