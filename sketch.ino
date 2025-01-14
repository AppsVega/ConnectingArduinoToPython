#define LED_pin 2
#define LED_error_pin 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_pin, OUTPUT);
  pinMode(LED_error_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //String msg = "STATIC";
  if (Serial.available() > 0) {
    String msg = Serial.readString();
    if (msg == "ON") {
      digitalWrite(LED_pin, HIGH);
    }
    else if (msg == "OFF") {
      digitalWrite(LED_pin, LOW);
    }

    else {
      digitalWrite(LED_error_pin, HIGH);
      delay(100);
      digitalWrite(LED_error_pin, LOW);
    }
  }
}