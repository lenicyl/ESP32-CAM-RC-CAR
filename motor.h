#ifndef MOTOR_H
#define MOTOR_H

#define PWMA 1
#define AIN2 13
#define AIN1 12
#define STBY 0
#define BIN1 3
#define BIN2 15
#define PWMB 14

int fb, rl; // Forward/Backward and Left/Right
void set_speed(int fb_speed, int rl_speed) {
  fb = fb_speed;
  rl = rl_speed;
}

// Call this function in main setup
void setupmotors() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void motor(int motor, int speed, int direction) {
  digitalWrite(STBY, HIGH);

  bool p1, p2;
  if (direction == 1) {
    p1 = HIGH;
    p2 = LOW;
  } else if (direction == -1) {
    p1 = LOW;
    p2 = HIGH;
  } else if (direction == 0) {
    p1 = HIGH;
    p2 = HIGH;
  }

  if (motor == 1) {
    digitalWrite(AIN1, p1);
    digitalWrite(AIN2, p2);
    analogWrite(PWMA, speed);
  } else if (motor == 2) {
    digitalWrite(BIN1, p1);
    digitalWrite(BIN2, p2);
    analogWrite(PWMB, speed);
  }
}


void stop() {
  motor(1, 0, 0);
  motor(2, 0, 0);
  digitalWrite(STBY, LOW);
}

void forward() {
  
  motor(1, fb, 1);
  motor(2, fb, 1);
}

void backward() {
  motor(1, fb, -1);
  motor(2, fb, -1);
}

void left() {
  motor(1, rl, 1);
  motor(2, rl, -1);
}

void right() {
  motor(1, rl, -1);
  motor(2, rl, 1);
}

#endif

