#include <Servo.h>

// Definir los pines para los servos
#define BASE_PIN 2
#define SHOULDER_PIN 3
#define ELBOW_PIN 4
#define WRIST_PIN 5
#define GRIPPER_PIN 6

// Definir los objetos Servo
Servo base_servo;
Servo shoulder_servo;
Servo elbow_servo;
Servo wrist_servo;
Servo gripper_servo;

// Variables para almacenar el estado actual de los servos
int base_pos = 90;
int shoulder_pos = 90;
int elbow_pos = 90;
int wrist_pos = 90;
int gripper_pos = 0;

void setup() {
  // Inicializar los pines de los servos
  base_servo.attach(BASE_PIN);
  shoulder_servo.attach(SHOULDER_PIN);
  elbow_servo.attach(ELBOW_PIN);
  wrist_servo.attach(WRIST_PIN);
  gripper_servo.attach(GRIPPER_PIN);

  // Inicializar los servos en la posición central
  base_servo.write(base_pos);
  shoulder_servo.write(shoulder_pos);
  elbow_servo.write(elbow_pos);
  wrist_servo.write(wrist_pos);
  gripper_servo.write(gripper_pos);

  // Inicializar la conexión Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Leer los datos de Bluetooth
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Controlar el brazo según el comando recibido
    switch (command) {
      case 'b':
        base_pos = (base_pos + 10) % 180;
        base_servo.write(base_pos);
        break;
      case 's':
        shoulder_pos = (shoulder_pos + 10) % 180;
        shoulder_servo.write(shoulder_pos);
        break;
      case 'e':
        elbow_pos = (elbow_pos + 10) % 180;
        elbow_servo.write(elbow_pos);
        break;
      case 'w':
        wrist_pos = (wrist_pos + 10) % 180;
        wrist_servo.write(wrist_pos);
        break;
      case 'g':
        gripper_pos = (gripper_pos + 1) % 2;
        gripper_servo.write(gripper_pos * 180);
        break;
    }
  }
}

