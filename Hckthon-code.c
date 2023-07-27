const int pingPin = A0; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A1; // Echo Pin of Ultrasonic Sensor
const int cm = 0;
char Incoming_value=0;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(A5, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(11, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
  if (cm < 6){
   delay(100);
   digitalWrite(A5, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(13, HIGH);
  }
  if (cm > 6){
    Serial.print("LEAK FOUND \n");
    digitalWrite(A5, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    delay(1000);
    if(Serial.available() > 0){
    Incoming_value=Serial.read();
    Serial.println(Incoming_value);
    
    if(Incoming_value == '1'){
      digitalWrite(12, HIGH);
      Serial.println("ON");
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      Serial.print("Going in to position \n");
      delay(2000);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(11, HIGH);
      Serial.print("Pumping \n");
      delay(4000);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      


    }
    else if(Incoming_value == '0'){
      digitalWrite(12, LOW);
      Serial.println("OFF");
    }
  }


  }

}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

