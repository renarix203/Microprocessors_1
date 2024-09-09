#include <Arduino.h>

void nums(int num);
void flush();
void pwm(int c, int perc);
void loading();

void asetup()
{
  for (int i = 2; i < 9; i++) {
  	  pinMode(i, OUTPUT);
  }
}

void aloop() {
  for (int i = 0; i < 10; i++) {
  	nums(i);
    delay(500);
    flush();
  }
  loading();
  flush();
}

void loading() {
  for (int i = 4; i > -1; i--) {
    int perc = i * 25;
    pwm(2, perc);
    delay(10);
    pwm(3, perc);
    delay(10);
    pwm(4, perc);
    delay(10);
    pwm(5, perc);
    delay(10);
    pwm(6, perc);
    delay(10);
    pwm(7, perc);
  }
}

void pwm(int c, int perc) {
  // PWM (pulse with modulation)
  int complete = 20;
  int i = (complete * perc) / 100;
  int off = complete - i;
  digitalWrite(c, 1);
  delay(i);
  digitalWrite(c, 0);
  delay(off);
}

void flush() {
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
}

void nums(int num) {
  if (num == 1) {
  	digitalWrite(3, 1);
    digitalWrite(4, 1);
  } else if (num == 2) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(8, 1);
    digitalWrite(6, 1);
    digitalWrite(5, 1);
  } else if (num == 3) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(8, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
  } else if (num == 4) {
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
  } else if (num == 5) {
    digitalWrite(2, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
  } else if (num == 6) {
    digitalWrite(2, 1);
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(8, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
  } else if (num == 7) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
  } else if (num == 8) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
  } else if (num == 9) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
  } else if (num == 0) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
  }
}
