#include<Arduino.h>
#define BUTTON_PIN 2

unsigned long currentMillis, previousMillis;
int currentButtonState, lastButtonState, lastDebouncedButtonState;
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  currentMillis = millis();
  //digitalWrite(3, HIGH);
}

void loop() {
  currentMillis = millis();
  currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState != lastButtonState) {
    previousMillis = millis();
    lastDebouncedButtonState = currentButtonState;
  }
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    Serial.println("Button Pressed");
  }
  else if(currentButtonState == HIGH && lastButtonState == LOW){
    Serial.println("Button Released"); 
  }
  lastButtonState = currentButtonState;
}