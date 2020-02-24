/* TODO:
 *  Use beeper as vibration motor.  This is definetly needed and is not something I came up with in the middle of the night
 */

#include <XInput.h>

int button[] = {0, 1, 2, 3, 4, 5, 6};
int hat1[] = {7, 8, 9, 10}; // Up, down, left, right
int hat2[] = {11, A3, A4, A5};

uint8_t xButton[] = {0, BUTTON_L3, BUTTON_LB, BUTTON_BACK, BUTTON_START, BUTTON_RB, BUTTON_R3}; //button[]
uint8_t xDPad[] = {DPAD_UP, DPAD_DOWN, DPAD_LEFT, DPAD_RIGHT}; //hat1[]
uint8_t xFace[] = {BUTTON_Y, BUTTON_A, BUTTON_X, BUTTON_B}; //hat2[]

int yoke = A0;
int lever = A1;
int push = A2;
void setup() {
  // put your setup code here, to run once:
  XInput.begin();

  XInput.setJoystickRange(0, 1024);
  XInput.setTriggerRange(0,1024);
  
  for (int i = 1; i <= 6; ++i) {
    pinMode(button[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 4; ++i) {
    pinMode(hat1[i], INPUT_PULLUP);
    pinMode(hat2[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 4; ++i){//Check for hats
    if(!digitalRead(hat1[i]))
      XInput.press(xDPad[i]);
      
    if(!digitalRead(hat2[i]))
      XInput.press(xFace[i]);

    if(digitalRead(hat1[i]))
      XInput.release(xDPad[i]);
      
    if(digitalRead(hat2[i]))
      XInput.release(xFace[i]);    
  }

  for (int i = 1; i <= 6; ++i){//Check for buttons
    if(!digitalRead(button[i]))
      XInput.press(xButton[i]);
    if(digitalRead(button[i]))
      XInput.release(xButton[i]);
  }

  //Read axis
  int32_t x = analogRead(yoke);
  uint32_t y = analogRead(push);
  uint32_t leverPos = analogRead(lever);

  //Invert X axis
  x = abs(x - 1024);
  
  XInput.setJoystick(JOY_LEFT, x, y);
  XInput.setTrigger(TRIGGER_RIGHT, leverPos);
}
