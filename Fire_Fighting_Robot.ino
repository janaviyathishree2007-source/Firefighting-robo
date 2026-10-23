#define enA 2//Enable1 L298 Pin enA
#define in1 3 //Motor1 L298 Pin in1
#define in2 4 //Motor1 L298 Pin in2
#define in3 5 //Motor2 L298 Pin in3

#define in4 6 //Motor2 L298 Pin in4
#define enB 7 //Enable2 L298 Pin enB
#define ir_R A2
#define ir_F A1
#define ir_L A0
#define servo A4
#define pump A3
#define buzzer 8
#define trigPin 9
#define echoPin 10
int Speed = 150; // Write The Duty Cycle 0 to 255 Enable for Motor Speed
int s1, s2, s3;
long duration;
int distance;
void setup(){ // put your setup code here, to run once
Serial.begin(9600); // start serial communication at 9600bps
pinMode(ir_R, INPUT);// declare fire sensor pin as input
pinMode(ir_F, INPUT);// declare fire sensor pin as input
pinMode(ir_L, INPUT);// declare fire sensor pin as input
pinMode(enA, OUTPUT); // declare as output for L298 Pin enA
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB
pinMode(servo, OUTPUT);
pinMode(pump, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin, INPUT);

for (int angle = 90; angle <= 140; angle += 5) {
servoPulse(servo, angle); }
for (int angle = 140; angle >= 40; angle -= 5) {
servoPulse(servo, angle); }
for (int angle = 40; angle <= 95; angle += 5) {
servoPulse(servo, angle); }
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed

delay(500);
}
void loop(){
  digitalWrite(pump,HIGH);
s1 = analogRead(ir_R);
s2 = analogRead(ir_F);

s3 = analogRead(ir_L);

//=============================================================
// Auto Control
//=============================================================
Serial.print(s1);
Serial.print("\t");
Serial.print(s2);
Serial.print("\t");
Serial.println(s3);
delay(50);
// ===== ULTRASONIC DISTANCE MEASUREMENT =====
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.println(distance);
// ===== OBSTACLE DETECTION USING DISTANCE =====
if(distance <= 15) {   // 15 cm threshold
  digitalWrite(pump, LOW);
  digitalWrite(buzzer, HIGH);

  Stop();
  delay(100);

  backword();
  delay(300);

  turnRight();
  delay(300);

  Stop();
  digitalWrite(buzzer, LOW);
  return;
}
if(s1<250){
Stop();
digitalWrite(pump, HIGH);
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100);
for(int angle = 90; angle >= 40; angle -= 3){
servoPulse(servo, angle);
}
for(int angle = 40; angle <= 90; angle += 3){
servoPulse(servo, angle);
}
}
else if(s2<350){
Stop();
digitalWrite(pump, HIGH);
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100);
for(int angle = 90; angle <= 140; angle += 3){
servoPulse(servo, angle);
}
for(int angle = 140; angle >= 40; angle -= 3){
servoPulse(servo, angle);
}
for(int angle = 40; angle <= 90; angle += 3){
servoPulse(servo, angle);
}
Serial.print("Pump State: ");
Serial.println(digitalRead(pump));
}
else if(s3<250){
Stop();

digitalWrite(pump, HIGH);
digitalWrite(buzzer, HIGH); 
delay(100); 
digitalWrite(buzzer, LOW); 
delay(100); 
for(int angle = 90; angle <= 140; angle += 3){
servoPulse(servo, angle);
}
for(int angle = 140; angle >= 90; angle -= 3){
servoPulse(servo, angle);
}
}
else if(s1>=251 && s1<=700){
digitalWrite(pump, LOW);
backword();
delay(100);
turnRight();
delay(200);
}
else if(s2>=251 && s2<=800){
digitalWrite(pump, LOW);
forword();
}
else if(s3>=251 && s3<=700){
digitalWrite(pump, LOW);
backword();
delay(100);
turnLeft();
delay(200);
}
else{
digitalWrite(pump, LOW);
Stop();
}
delay(10);
}
void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500; // Convert angle to microseconds
digitalWrite(pin, HIGH);
delayMicroseconds(pwm);
digitalWrite(pin, LOW);

delay(50); // Refresh cycle of servo
}
void backword(){ //
digitalWrite(in1, HIGH); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, HIGH); //Left Motor forword Pin
}
void forword(){ //
digitalWrite(in1, LOW); //Right Motor forword Pin
digitalWrite(in2, HIGH); //Right Motor backword Pin
digitalWrite(in3, HIGH); //Left Motor backword Pin
digitalWrite(in4, LOW); //Left Motor forword Pin
}
void turnRight(){ //
digitalWrite(in1, LOW); //Right Motor forword Pin
digitalWrite(in2, HIGH); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, HIGH); //Left Motor forword Pin
}
void turnLeft(){ //
digitalWrite(in1, HIGH); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, HIGH); //Left Motor backword Pin
digitalWrite(in4, LOW); //Left Motor forword Pin
}
void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, LOW); //Left Moto
