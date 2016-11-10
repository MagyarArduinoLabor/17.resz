#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);
char state; 

int motor1Pin1 = 3; // pin 2 on L293D IC
int motor1Pin2 = 4; // pin 7 on L293D IC
int enable1Pin = 6; // pin 1 on L293D IC
int motor2Pin1 = 8; // pin 10 on L293D IC
int motor2Pin2 = 9; // pin 15 on L293D IC
int enable2Pin = 11; // pin 9 on L293D IC

//
void setup() {
//
Serial.begin(9600);
Serial.println("Bluetooth kommunikáció inicializása");
mySerial.begin(9600);
mySerial.println("Bluetooth kommunikáció inicializása"); //beállítás outputként

pinMode(motor1Pin2, OUTPUT);
pinMode(motor1Pin1, OUTPUT);
pinMode(enable1Pin, OUTPUT);
pinMode(motor2Pin1, OUTPUT);
pinMode(motor2Pin2, OUTPUT);
pinMode(enable2Pin, OUTPUT);
//
digitalWrite(enable1Pin, HIGH);
digitalWrite(enable2Pin, HIGH);
}

void loop() {
if (mySerial.available()) {
//kommunikáció elérhető
state = mySerial.read();// a bluetooth vevő értéke,
// JOBBRA /////////////////////////////////////////
if (state == 'R' || state == 'r') {
digitalWrite(motor1Pin2,HIGH);
digitalWrite(motor1Pin1,LOW);
digitalWrite(motor2Pin1,LOW);
digitalWrite(motor2Pin2,HIGH); }
// BALRA /////////////////////////////////////////
if (state == 'L' || state == 'l') {
digitalWrite(motor1Pin2,LOW);
digitalWrite(motor1Pin1,HIGH);
digitalWrite(motor2Pin1,HIGH);
digitalWrite(motor2Pin2,LOW); }
// ELŐRE /////////////////////////////////////////
if (state == 'F' || state == 'f') {
digitalWrite(motor1Pin2,LOW);
digitalWrite(motor1Pin1,HIGH);
digitalWrite(motor2Pin1,LOW);
digitalWrite(motor2Pin2,HIGH); }
// HÁTRA /////////////////////////////////////
if (state == 'B' || state == 'b') {
digitalWrite(motor1Pin2,HIGH);
digitalWrite(motor1Pin1,LOW);
digitalWrite(motor2Pin1,HIGH);
digitalWrite(motor2Pin2,LOW); }
// STOP /////////////////////////////////////////
if (state == 'S' || state == 'w') {
digitalWrite(motor1Pin2,HIGH);
digitalWrite(motor1Pin1,HIGH);
digitalWrite(motor2Pin1,HIGH);
digitalWrite(motor2Pin2,HIGH); }
}
}

