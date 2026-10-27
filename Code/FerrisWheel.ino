#define EN 2
#define STEP 3
#define DIR 4

void setup() {
  pinMode(EN, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
}

void loop() {
  moveStepper(0, 1);
}

void moveStepper(int dir, int steps) {
  digitalWrite(DIR, dir);
  digitalWrite(EN, 0);

  for (int i = 0; i < steps*16; i++) {
    digitalWrite(STEP, 1);
    delayMicroseconds(7200/16);
    digitalWrite(STEP, 0);
    delayMicroseconds(7200/16);
  }

  digitalWrite(EN, 1);
}
