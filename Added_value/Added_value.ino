#include <Servo.h>
#include <Math.h>

Servo servo1;
Servo servo2;

double pos_servo1 = 0;
double pos_servo2 = 0;
int offsetX = 15;
int offsetY = 15;


void setup(void)
{
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  servo1.attach(2);
  servo2.attach(3);
}

void loop(void)
{

  if (gyro.gyro.x > 5) {
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
  if (gyro.gyro.y > 5) {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }

  if (gyro.gyro.z > 5) {
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }

  double map_out_start = 180;
  double map_out_end = 40;
  double map_in_start = -10;
  double map_in_end = 10;

  double m1 = 1.0 * (map_out_end - map_out_start) / (map_in_end - map_in_start);
  pos_servo1 = map_out_start + m1* (accel.acceleration.x - map_in_start);
  servo1.write(pos_servo1 - offsetX);
  pos_servo2 = map_out_start + m1* (accel.acceleration.y - map_in_start);
  servo2.write(pos_servo2 - offsetY);

  delay(10);
}
