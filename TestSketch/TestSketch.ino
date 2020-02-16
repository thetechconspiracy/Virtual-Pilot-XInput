/* TODO:
 *  Add XInput support
 *  Use beeper as vibration motor.  This is definetly needed and is not something I came up with in the middle of the night
 */

#include <XInput.h>

int button[] = {0, 1, 2, 3, 4, 5, 6};
int hat1[] = {7, 8, 9, 10}; // Up, down, left, right
int hat2[] = {11, A3, A4, A5};

int yoke = A0;
int push = A1;
int lever = A2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 1; i <= 6; ++i) {
    pinMode(button[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 4; ++i) {
    pinMode(hat1[i], INPUT_PULLUP);
    pinMode(hat2[i], INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i <= 6; ++i) {
    Serial.print(digitalRead(button[i]));
  }
  Serial.print("\t");
  for (int i = 0; i < 4; ++i) {
    Serial.print(digitalRead(hat1[i]));
  }
  Serial.print("\t");
  for (int i = 0; i < 4; ++i) {
    Serial.print(digitalRead(hat2[i]));
  }

  Serial.print("\t");
  Serial.print(analogRead(yoke));
  Serial.print("\t");
  Serial.print(analogRead(push));
  Serial.print("\t");
  Serial.print(analogRead(lever));

  Serial.println();

}
