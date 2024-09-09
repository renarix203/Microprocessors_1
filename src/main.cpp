#include <Arduino.h>

const int RED_LED_PIN = 3;
const int YELLOW_LED_PIN = 5;
const int GREEN_LED_PIN = 7;

const int SW1_PIN = 2;
const int SW2_PIN = 4;
const int SW3_PIN = 6;

int red_state = 0;
int new_red_state = 0;
int red_pushed = 0;
unsigned long red_time = 0;
unsigned long red_start = 0;
unsigned long red_press1 = 0;
unsigned long red_press2 = 0;
unsigned long red_press3 = 0;
unsigned long red_pattern1 = 0;
unsigned long red_pattern2 = 0;
unsigned long red_pattern3 = 0;
unsigned long red_pattern4 = 0;
unsigned long red_pattern5 = 0;
unsigned long red_pattern6 = 0;
unsigned long red_pattern7 = 0;
unsigned long red_pattern8 = 0;
unsigned long red_pattern9 = 0;

int yellow_state = 0;
int new_yellow_state = 0;
int yellow_pushed = 0;
unsigned long yellow_time = 0;
unsigned long yellow_start = 0;
unsigned long yellow_press1 = 0;
unsigned long yellow_press2 = 0;
unsigned long yellow_press3 = 0;
unsigned long yellow_pattern1 = 0;
unsigned long yellow_pattern2 = 0;
unsigned long yellow_pattern3 = 0;
unsigned long yellow_pattern4 = 0;
unsigned long yellow_pattern5 = 0;
unsigned long yellow_pattern6 = 0;
unsigned long yellow_pattern7 = 0;
unsigned long yellow_pattern8 = 0;
unsigned long yellow_pattern9 = 0;

int green_state = 0;
int new_green_state = 0;
int green_pushed = 0;
unsigned long green_time = 0;
unsigned long green_start = 0;
unsigned long green_press1 = 0;
unsigned long green_press2 = 0;
unsigned long green_press3 = 0;
unsigned long green_pattern1 = 0;
unsigned long green_pattern2 = 0;
unsigned long green_pattern3 = 0;
unsigned long green_pattern4 = 0;
unsigned long green_pattern5 = 0;
unsigned long green_pattern6 = 0;
unsigned long green_pattern7 = 0;
unsigned long green_pattern8 = 0;
unsigned long green_pattern9 = 0;


void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  Serial.begin(9600);

  pinMode(SW1_PIN, INPUT_PULLUP);
  pinMode(SW2_PIN, INPUT_PULLUP);
  pinMode(SW3_PIN, INPUT_PULLUP);
}

void loop() {
  // digitalWrite(RED_LED_PIN, digitalRead(SW1_PIN) ? LOW : HIGH);
  red_state = new_red_state;
  if (digitalRead(SW1_PIN) == HIGH) {
    digitalWrite(RED_LED_PIN, LOW);
    new_red_state = 1;
  } else {
    digitalWrite(RED_LED_PIN, HIGH);
    new_red_state = 0;
  }
  if ((red_state == 1 && new_red_state == 0)) {
    unsigned long start_time = millis();
    red_time = start_time;
    red_pushed++;
    Serial.print("Red: "); Serial.println(red_pushed);
  } else if (red_state == 0 && new_red_state == 1) {
    unsigned long end_time = millis();
    red_time = end_time - red_time;
    Serial.print("Red time: "); Serial.print(red_time); Serial.println(" ms");

    red_press1 = red_press2;
    red_press2 = red_press3;
    red_press3 = red_time;

    red_pattern1 = red_pattern2;
    red_pattern2 = red_pattern3;
    red_pattern3 = red_pattern4;
    red_pattern4 = red_pattern5;
    red_pattern5 = red_pattern6;
    red_pattern6 = red_pattern7;
    red_pattern7 = red_pattern8;
    red_pattern8 = red_pattern9;
    red_pattern9 = red_time;
  }

  // ..- pattern
  if (red_press1 != 0 && red_press2 != 0 && red_press3 != 0) {
    if (red_press1 <= 200 && red_press2 <= 200 && red_press3 > 200) {
      Serial.println("..- Pattern Recognized");

      // reset all
      red_press1 = 0;
      red_press2 = 0;
      red_press3 = 0;

      // red_pattern1 = 0;
      // red_pattern2 = 0;
      // red_pattern3 = 0;
      // red_pattern4 = 0;
      // red_pattern5 = 0;
      // red_pattern6 = 0;
      // red_pattern7 = 0;
      // red_pattern8 = 0;
      // red_pattern9 = 0;
    }
  }

  // ...---... pattern
  if (red_pattern1 != 0 && red_pattern2 != 0 && red_pattern3 != 0 && red_pattern4 != 0 && red_pattern5 != 0 && red_pattern6 != 0 && red_pattern7 != 0 && red_pattern8 != 0 && red_pattern9 != 0) {
    if (red_pattern1 <= 200 && red_pattern2 <= 200 && red_pattern3 <= 200 && red_pattern4 > 200 && red_pattern5 > 200 && red_pattern6 > 200 && red_pattern7 <= 200 && red_pattern8 <= 200 && red_pattern9 <= 200) {
      Serial.println("...---... Pattern Recognized");

      // reset all
      red_press1 = 0;
      red_press2 = 0;
      red_press3 = 0;

      red_pattern1 = 0;
      red_pattern2 = 0;
      red_pattern3 = 0;
      red_pattern4 = 0;
      red_pattern5 = 0;
      red_pattern6 = 0;
      red_pattern7 = 0;
      red_pattern8 = 0;
      red_pattern9 = 0;
    }
  }

  yellow_state = new_yellow_state;
  if (digitalRead(SW2_PIN) == HIGH) {
    digitalWrite(YELLOW_LED_PIN, LOW);
    new_yellow_state = 1;
  } else {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    new_yellow_state = 0;
  }
  if ((yellow_state == 1 && new_yellow_state == 0)) {
    unsigned long start_time = millis();
    yellow_time = start_time;
    yellow_pushed++;
    Serial.print("Yellow: "); Serial.println(yellow_pushed);
  } else if (yellow_state == 0 && new_yellow_state == 1) {
    unsigned long end_time = millis();
    yellow_time = end_time - yellow_time;
    Serial.print("Yellow time: "); Serial.print(yellow_time); Serial.println(" ms");

    yellow_press1 = yellow_press2;
    yellow_press2 = yellow_press3;
    yellow_press3 = yellow_time;

    yellow_pattern1 = yellow_pattern2;
    yellow_pattern2 = yellow_pattern3;
    yellow_pattern3 = yellow_pattern4;
    yellow_pattern4 = yellow_pattern5;
    yellow_pattern5 = yellow_pattern6;
    yellow_pattern6 = yellow_pattern7;
    yellow_pattern7 = yellow_pattern8;
    yellow_pattern8 = yellow_pattern9;
    yellow_pattern9 = yellow_time;
  }
  // ..- pattern
  if (yellow_press1 != 0 && yellow_press2 != 0 && yellow_press3 != 0) {
    if (yellow_press1 <= 200 && yellow_press2 <= 200 && yellow_press3 > 200) {
      Serial.println("..- Pattern Recognized");
      yellow_press1 = 0;
      yellow_press2 = 0;
      yellow_press3 = 0;
    }
  }
    // ...---... pattern
  if (yellow_pattern1 != 0 && yellow_pattern2 != 0 && yellow_pattern3 != 0 && yellow_pattern4 != 0 && yellow_pattern5 != 0 && yellow_pattern6 != 0 && yellow_pattern7 != 0 && yellow_pattern8 != 0 && yellow_pattern9 != 0) {
    if (yellow_pattern1 <= 200 && yellow_pattern2 <= 200 && yellow_pattern3 <= 200 && yellow_pattern4 > 200 && yellow_pattern5 > 200 && yellow_pattern6 > 200 && yellow_pattern7 <= 200 && yellow_pattern8 <= 200 && yellow_pattern9 <= 200) {
      Serial.println("...---... Pattern Recognized");

      // reset all
      yellow_press1 = 0;
      yellow_press2 = 0;
      yellow_press3 = 0;

      yellow_pattern1 = 0;
      yellow_pattern2 = 0;
      yellow_pattern3 = 0;
      yellow_pattern4 = 0;
      yellow_pattern5 = 0;
      yellow_pattern6 = 0;
      yellow_pattern7 = 0;
      yellow_pattern8 = 0;
      yellow_pattern9 = 0;
    }
  }

  green_state = new_green_state;
  if (digitalRead(SW3_PIN) == HIGH) {
    digitalWrite(GREEN_LED_PIN, LOW);
    new_green_state = 1;
  } else {
    digitalWrite(GREEN_LED_PIN, HIGH);
    new_green_state = 0;
  }
  if ((green_state == 1 && new_green_state == 0)) {
    unsigned long start_time = millis();
    green_time = start_time;
    green_pushed++;
    Serial.print("Green: "); Serial.println(green_pushed);
  } else if (green_state == 0 && new_green_state == 1) {
    unsigned long end_time = millis();
    green_time = end_time - green_time;
    Serial.print("Green time: "); Serial.print(green_time); Serial.println(" ms");

    green_press1 = green_press2;
    green_press2 = green_press3;
    green_press3 = green_time;

    green_pattern1 = green_pattern2;
    green_pattern2 = green_pattern3;
    green_pattern3 = green_pattern4;
    green_pattern4 = green_pattern5;
    green_pattern5 = green_pattern6;
    green_pattern6 = green_pattern7;
    green_pattern7 = green_pattern8;
    green_pattern8 = green_pattern9;
    green_pattern9 = green_time;
  }
  if (green_press1 != 0 && green_press2 != 0 && green_press3 != 0) {
    if (green_press1 <= 200 && green_press2 <= 200 && green_press3 > 200) {
      Serial.println("..- Pattern Recognized");
      green_press1 = 0;
      green_press2 = 0;
      green_press3 = 0;
    }
  }
      // ...---... pattern
  if (green_pattern1 != 0 && green_pattern2 != 0 && green_pattern3 != 0 && green_pattern4 != 0 && green_pattern5 != 0 && green_pattern6 != 0 && green_pattern7 != 0 && green_pattern8 != 0 && green_pattern9 != 0) {
    if (green_pattern1 <= 200 && green_pattern2 <= 200 && green_pattern3 <= 200 && green_pattern4 > 200 && green_pattern5 > 200 && green_pattern6 > 200 && green_pattern7 <= 200 && green_pattern8 <= 200 && green_pattern9 <= 200) {
      Serial.println("...---... Pattern Recognized");

      // reset all
      green_press1 = 0;
      green_press2 = 0;
      green_press3 = 0;

      green_pattern1 = 0;
      green_pattern2 = 0;
      green_pattern3 = 0;
      green_pattern4 = 0;
      green_pattern5 = 0;
      green_pattern6 = 0;
      green_pattern7 = 0;
      green_pattern8 = 0;
      green_pattern9 = 0;
    }
  }
  // digitalWrite(YELLOW_LED_PIN, digitalRead(SW2_PIN) ? LOW : HIGH);
  // digitalWrite(GREEN_LED_PIN, digitalRead(SW3_PIN) ? LOW : HIGH);

  // delay(20);
}
