// Motor 1
int M1_IN1 = 2;
int M1_IN2 = 4;
int M1_EN = 3;

// Motor 2
int M2_IN1 = 5;
int M2_IN2 = 7;
int M2_EN = 6;

// Motor 3
int M3_IN1 = 8;
int M3_IN2 = 10;
int M3_EN = 9;

// Motor 4
int M4_IN1 = 12;
int M4_IN2 = 13;
int M4_EN = 11;


void setup() {

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M1_EN, OUTPUT);

  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M2_EN, OUTPUT);

  pinMode(M3_IN1, OUTPUT);
  pinMode(M3_IN2, OUTPUT);
  pinMode(M3_EN, OUTPUT);

  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);
  pinMode(M4_EN, OUTPUT);
}

void forward(int in1, int in2, int en) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en, 200);
}

void backward(int in1, int in2, int en) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en, 200);
}

void stopMotor(int en) {
  analogWrite(en, 0);
}

void loop() {

  //forward (30 seconds)
  forward(M1_IN1, M1_IN2, M1_EN);
  forward(M2_IN1, M2_IN2, M2_EN);
  forward(M3_IN1, M3_IN2, M3_EN);
  forward(M4_IN1, M4_IN2, M4_EN);

  delay(30000);


  //backward (60 seconds)
  backward(M1_IN1, M1_IN2, M1_EN);
  backward(M2_IN1, M2_IN2, M2_EN);
  backward(M3_IN1, M3_IN2, M3_EN);
  backward(M4_IN1, M4_IN2, M4_EN);

  delay(60000);


  // Right and Left alternately (60 seconds)
  for(int i = 0; i < 3; i++) {

    // Turn Right
    forward(M2_IN1, M2_IN2, M2_EN);
    forward(M4_IN1, M4_IN2, M4_EN);

    stopMotor(M1_EN);
    stopMotor(M3_EN);

    delay(10000);

    // Turn Left
    forward(M1_IN1, M1_IN2, M1_EN);
    forward(M3_IN1, M3_IN2, M3_EN);

    stopMotor(M2_EN);
    stopMotor(M4_EN);

    delay(10000);
  }

  stopMotor(M1_EN);
  stopMotor(M2_EN);
  stopMotor(M3_EN);
  stopMotor(M4_EN);

  delay(5000);
}