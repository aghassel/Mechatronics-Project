const int TRIG = 6;
const int ECHO = 4;
const int LED_PIN = 11;

const float m = -0.25; //slope: (f2-f1)/(d2-d1)=(100-1)/(2-400)
const float b = 100.5; //y-int: b=y-mx=100-(-0.25)(2)

int diffTime;
float distance;
float period;

void setup() {
  
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(TRIG,LOW);
  
}

void loop() {
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  diffTime = pulseIn(ECHO,HIGH);
  period = 1 / (m * distance + b) * 1000;
  distance = diffTime * 0.035 / 2;

  if(period < 0){
    period = 0;
  }
  
  Serial.println(distance);
  Serial.println(period);

  digitalWrite(LED_PIN,HIGH);
  delay(period);
  
  digitalWrite(LED_PIN,LOW);
  delay(period);
  
}
