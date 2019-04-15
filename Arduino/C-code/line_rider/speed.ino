float SetSpeed(float speed) {
  speed = constrain(speed, -1.0, 1.0);
  MotorServo.writeMicroseconds(1600 + 250 * speed);
  delay(500);
}
