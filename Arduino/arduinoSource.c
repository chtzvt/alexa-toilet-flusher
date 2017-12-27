/*
  (c) Charlton Trezevant 2017 - MIT License

  Initially I was having trouble getting the CHIP to output PWM, or control
  the servo reliably.
  
  Before I managed to get that working on the CHIP itself, I used an Arduino
  as a liaison between the flushing API component (which is called by AVS) and
  the servo control.
  
  Using this, the CHIP would bring a GPIO pin high (which it could do reliably),
  and this would signal the Arduino to operate the flushing servo.
  
  Thankfully, this was no longer needed once I got the right kernel installed,
  and got the PWM setup script working correctly.
  
  So, you very likely won't need this sketch, but I'm keeping it in this repo
  because it is a very useful workaround if you're in a pinch.
*/

void setup() {
  pinMode(1, INPUT); // Pin 1 - GPIO input from CHIP
  pinMode(2, OUTPUT); // Pin 2 - PWM output to servo
}

void loop() {
  // To activate the flusher, bring pin 1 HIGH.
  if(digitalRead(1) == HIGH) {
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(2100);
    digitalWrite(2, LOW);
    delay(50);
    delay(1000);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delayMicroseconds(500);
    digitalWrite(2, LOW);
    delay(50);
    delay(1000);
  }
}
