#include <NewPing.h>
#include <AFMotor.h>
#include <Servo.h>

#define trigPin 9
#define echoPin 14
Servo myservo;// Variable del servo llamado myservo
AF_DCMotor motor1(1);
void setup() 
{
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 long duracion, distancia;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duracion = pulseIn(echoPin, HIGH);
 distancia = duracion/2/29.1;
 Serial.println(String(distancia)+" cm.");
 delay (100);
 if (distancia < 106) {//Si la distancia es menor a 106 
  motor1.run(RELEASE);
  myservo.attach(10);// Asigna el pin 10 al objeto myservo para controlar el servo
  motor1.setSpeed(250);// Establece la velocidad del motor en 250
  myservo.write(90);//Mueve el servo a la posición de 90 grados (inicial)
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(400);// Espera 1 segundos pega
  myservo.write(100);//Mueve el servo a la posición de 100 grados
  motor1.setSpeed(255); // Ajusta nuevamente la velocidad del motor a 250
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(2400); // Espera 2.5 segundos
 // terminar vuelta
 myservo.write(100);// Mantiene el servo en la posición de 100 grados
  motor1.setSpeed(255);// Establece la velocidad máxima del motor
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(9000); // Espera 25 segundos para completar las 3 vueltas 
  motor1.setSpeed(0);// Detiene el motor
  motor1.run(RELEASE); // Libera el motor (sin potencia)
}else{
  motor1.run(RELEASE);
  myservo.attach(10);// Asigna el pin 10 al objeto myservo para controlar el servo
  motor1.setSpeed(250);// Establece la velocidad del motor en 250
  myservo.write(90);//Mueve el servo a la posición de 90 grados (inicial)
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(1200);// Espera 1.7 segundos
  myservo.write(100);//Mueve el servo a la posición de 100 grados
  motor1.setSpeed(255); // Ajusta nuevamente la velocidad del motor a 250
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(2500); // Espera 2.5 segundos
 // terminar vuelta
 myservo.write(100);// Mantiene el servo en la posición de 100 grados
  motor1.setSpeed(250);// Establece la velocidad máxima del motor
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(14000); // Espera 27 segundos para completar las 3 vueltas 
  motor1.setSpeed(0);// Detiene el motor
  motor1.run(RELEASE); // Libera el motor (sin potencia)
}
}
void loop() {

}
