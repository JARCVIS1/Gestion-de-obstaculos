#include<Servo.h>// Incluye la librería para controlar el servo
#include<AFMotor.h>// Incluye la librería para controlar el motor L293D
Servo myservo;// Variable del servo llamado myservo
AF_DCMotor motor1(1); //Motor1 para controlar el motor en el puerto 1 del controlador L293D
void setup()
{
 motor1.run(RELEASE);
  myservo.attach(10);// Asigna el pin 10 al objeto myservo para controlar el servo
  motor1.setSpeed(250);// Establece la velocidad del motor en 250
  myservo.write(90);//Mueve el servo a la posición de 90 grados (inicial)
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(1700);// Espera 1.7 segundos
  myservo.write(100);//Mueve el servo a la posición de 100 grados
  motor1.setSpeed(250); // Ajusta nuevamente la velocidad del motor a 250
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(2500); // Espera 2.5 segundos
 myservo.write(100);// Mantiene el servo en la posición de 100 grados
  motor1.setSpeed(255);// Establece la velocidad máxima del motor
  motor1.run(FORWARD);// Configura el motor para que gire hacia adelante
  delay(27000); // Espera 27 segundos para completar las 3 vueltas 
  motor1.setSpeed(0);// Detiene el motor
  motor1.run(RELEASE); // Libera el motor (sin potencia)
}

void loop(){
  // El loop está vacío ya que la acción se realiza solo una vez en setup
}
