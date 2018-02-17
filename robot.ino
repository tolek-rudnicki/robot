#include <Servo.h>

Servo s1, s2, s3, s4;

int poz1 = 0, poz2 = 0, poz3 = 0;
int pinPot1 = 1;
int pinPot2 = 0;

void setup() {
    pinMode(2, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);

    s1.attach(8);
    s2.attach(9);
    s3.attach(10);
    s4.attach(11);
}

void loop() {

    digitalWrite(LED_BUILTIN, HIGH);
    
    poz1 = analogRead(pinPot1);
    poz1 = map(poz1, 0, 1023, 0, 180);
    s1.write(poz1);

    poz2 = analogRead(pinPot2);
    poz2 = map(poz2, 0, 1023, 0, 180);
    s2.write(poz2);

    poz3 = analogRead(pinPot2);
    poz3 = map(poz3, 0, 1023, 180, 0);
    s3.write(poz3);

    if (digitalRead(2) != LOW) {
        s4.write(180);
    } else {
        s4.write(0);
    }

    delay(55);
    digitalWrite(LED_BUILTIN, LOW);
    delay(55);
  
}

