#include<Arduino.h>
#define BUTTON_PIN 12
#define LED1 13
#define LED2 14

unsigned long currentMillis, previousMillis;
int currentButtonState, lastButtonState, lastDebouncedButtonState;
int state = 0;
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(115200);
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
      state++;
      if (state > 3){
        state = 0;
      }
      Serial.println("Button Pressed");
      Serial.println(state);
    }
    else if(lastButtonState == LOW && currentButtonState == HIGH){
      Serial.println("Button Released");
    }
    lastButtonState = currentButtonState;
  }

  switch (state) {
    case 0:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      break;
    case 1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      break;
    case 2:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      break;
    case 3:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      break;
  }
}