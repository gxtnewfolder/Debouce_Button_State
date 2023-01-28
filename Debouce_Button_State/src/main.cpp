#include<Arduino.h>
#define BUTTON_PIN 2

unsigned long currentMillis, previousMillis;
int currentButtonState, lastButtonState, lastDebouncedButtonState;
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  currentMillis = millis();
  previousMillis = currentMillis;
}

void loop() {
  currentMillis = millis();
  currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState != lastDebouncedButtonState) {
    previousMillis = millis();
    lastDebouncedButtonState = currentButtonState;
  }
  if((currentMillis - previousMillis) > 50 ){
    if (lastButtonState == HIGH && currentButtonState == LOW) {
      Serial.println("Button Pressed");
    }
    else if(lastButtonState == LOW && currentButtonState == HIGH){
      Serial.println("Button Released"); 
    }
    lastButtonState = currentButtonState;
  }
  
}