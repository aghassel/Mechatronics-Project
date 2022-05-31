const int TRIG = 6;
const int ECHO = 4;
int diffTime;
double distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG,LOW);
}

void loop() {
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  diffTime = pulseIn(ECHO, HIGH);
  distance = diffTime*0.035/2;

  Serial.println(distance);
  delay(100);
}
