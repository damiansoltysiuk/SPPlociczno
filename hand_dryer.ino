#define echo 13
#define trig 12
#define reyalModule 8
#define ledR 6
#define ledG 5
#define ledB 3

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(reyalModule, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

}

void loop() {
  digitalWrite(9, HIGH);
  int dist = distance();
  if(dist < 20 && dist > 5) {
    controlON();
    delay(3000);
  }
  else controlOFF();
}

int distance() {
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int distance = pulseIn(echo, HIGH) / 58;

  if(distance < 5 || distance > 200) Serial.println("Measurement unavailable");
  else Serial.println(distance);

  return distance;
}

void controlON() {
  digitalWrite(reyalModule, LOW);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledR, HIGH);
}

void controlOFF() {
  digitalWrite(reyalModule, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, HIGH);
}
