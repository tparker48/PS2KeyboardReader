#ifndef PS2Keyboard_h
#define PS2Keyboard_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" // for attachInterrupt, FALLING
#else
#include "WProgram.h"
#endif

#include "utility/int_pins.h"

#define PS2_A 100
#define PS2_B 1
#define PS2_C 2
#define PS2_D 3
#define PS2_E 4
#define PS2_F 5
#define PS2_G 6
#define PS2_H 7
#define PS2_I 8
#define PS2_J 9
#define PS2_K 10
#define PS2_L 11
#define PS2_M 12
#define PS2_N 13
#define PS2_O 14
#define PS2_P 15
#define PS2_Q 16
#define PS2_R 17
#define PS2_S 18
#define PS2_T 19
#define PS2_U 20
#define PS2_V 21
#define PS2_W 22
#define PS2_X 23
#define PS2_Y 24
#define PS2_Z 25

#define PS2_1 26
#define PS2_2 27
#define PS2_3 29
#define PS2_4 30
#define PS2_5 31
#define PS2_6 32
#define PS2_7 33
#define PS2_8 34
#define PS2_9 35
#define PS2_0 36



#define PS2_N0 37
#define PS2_N1 38
#define PS2_N2 39
#define PS2_N3 40
#define PS2_N4 41
#define PS2_N5 42
#define PS2_N6 43
#define PS2_N7 44
#define PS2_N8 45
#define PS2_N9 46
#define PS2_NUMLOCK 47
#define PS2_N_MINUS 48
#define PS2_N_DIVIDE 49

#define PS2_N_DOT 111
#define PS2_N_PLUS 112
#define PS2_N_TIMES 113

#define PS2_SPACE 52
#define PS2_COMMA 53
#define PS2_PERIOD 54
#define PS2_FORWARD_SLASH 55
#define PS2_BACKWARD_SLASH 56
#define PS2_SEMI_COLON 57
#define PS2_DASH 58
#define PS2_APOSTROPHE 59
#define PS2_OPEN_BRACE 60
#define PS2_CLOSE_BRACE 61
#define PS2_EQUALS 62
#define PS2_CAPS 63
#define PS2_LSHIFT 64
#define PS2_RSHIFT 65
#define PS2_LALT 66
#define PS2_RALT 114
#define PS2_LCTRL 67
#define PS2_RCTRL 115
#define PS2_LOS 116
#define PS2_ROS 117
#define PS2_MENU 118

#define PS2_TAB				69
#define PS2_ENTER			70
#define PS2_BACKSPACE			71
#define PS2_ESC				72
#define PS2_INSERT			73
#define PS2_DELETE			74
#define PS2_HOME			75
#define PS2_END				76
#define PS2_PAGEUP			77
#define PS2_PAGEDOWN			78
#define PS2_UPARROW			79
#define PS2_LEFTARROW			80
#define PS2_DOWNARROW			81
#define PS2_RIGHTARROW			82

#define PS2_F1				83
#define PS2_F2				84
#define PS2_F3				85
#define PS2_F4				86
#define PS2_F5			  87
#define PS2_F6				88
#define PS2_F7				89
#define PS2_F8				90
#define PS2_F9				91
#define PS2_F10				92
#define PS2_F11				93
#define PS2_F12				94
#define PS2_SCROLL			95


#define PS2_KEYMAP_SIZE 136
#define KEY_MAX 256

typedef struct {
	uint8_t keys[PS2_KEYMAP_SIZE];
} PS2Keymap_t;
extern const PROGMEM PS2Keymap_t PS2Keymap;

extern bool keystates[KEY_MAX];
extern bool keyup[KEY_MAX];

class PS2Keyboard {
  public:
    PS2Keyboard();

    static void begin(uint8_t dataPin, uint8_t irq_pin, const PS2Keymap_t &map = PS2Keymap);
    static bool available();
    static void refresh();

    bool key_down(int key){ return keystates[key]; }

    // toggle on/off behavior for key
    bool key_toggle(int key){ 
      if (keyup[key]){
        keyup[key] = false;
        return true;  
      }
      return false;
    }
};

#endif
