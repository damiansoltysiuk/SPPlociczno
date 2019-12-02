#define relay_module 10

void setup() {
  pinMode(relay_module, OUTPUT);
}

void loop() {
  digitalWrite(relay_module, HIGH);
  delay(1000);
  digitalWrite(relay_module, LOW);
  delay(2000);
}
