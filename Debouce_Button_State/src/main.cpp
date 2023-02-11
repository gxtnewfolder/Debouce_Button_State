#include<Arduino.h>
#define BUTTON_PIN 12
#define LED1 13
#define LED2 14

unsigned long curr, prev;
int state = 0;

int button_state(void){
  int x = 0;
  curr = millis()/100;
  if(curr != prev){
    prev = curr;
    int btn = digitalRead(BUTTON_PIN);
    if(state == 0){
      if(btn == LOW){
        state = 1;
        x = 1;
      }
    }
    else if(state == 1){
      if(btn == LOW){
        state = 2;
        Serial.println("Button pressed");
      }
      else{
        state = 0;
      }
    }
    else if(state == 2){
      if(btn == HIGH){
        state = 3;
      }
      else{
        x = 2;
      }
    }
    else if(state == 3){
      if(btn == HIGH){
        state = 0;
        Serial.println("Button released");
      }
      else{
        state = 2;
      }
    }
  }
  return x;
}
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(115200);
  
}

void loop() {
  int bn;
  bn = button_state();
  if(bn == 1){
    Serial.println("Button pressed");
  }
}