/* connect the trig and echo pins to whichever digital pins you chose.
I chose 9 and 10. Then connect VCC to 5V and GND to ground. */  
int trig = 9;
int echo = 10;

//runs once on power up 
void setup() {
    // make trig and output and echo and input
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);

    //set the serial at 9600 baud
    Serial.begin(9600); 
}

//loops while the arduino is powered 
void loop() {
    // set trig to low
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // read from the trig pin for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // read echo and  return the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    // distance formula for sound waves
    int distance= duration*0.034/2;
    // print the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
}
