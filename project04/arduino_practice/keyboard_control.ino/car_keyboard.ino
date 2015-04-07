int F = 2;
int B = 4;
int L = 8;
int R = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(F, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(R, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int left, right, forward, backward;
  
  if (Serial.available() > 0) {
    // read incoming serial data:
    char command = Serial.read();
    left = LOW;
    right = LOW;
    forward = HIGH;
    backward = LOW;
    
    if(command == 'd') {
      Serial.println("Move forward");
      forward = HIGH;
      backward = LOW;
    }
    else if(command == 's') {
      Serial.println("Move backwards");
      forward = LOW;
      backward = HIGH;
    }
    else if(command == 'a') {
      Serial.println("Move left");
      left = HIGH;
      right = LOW;
    }
    else if(command == 'f') {
      Serial.println("Move right");
      left = LOW;
      right = HIGH;
    }
    else if(command == 'x'){
      Serial.println("STOP!");
      left = LOW;
      right = LOW;
      forward = LOW;
      backward = LOW;
    }
    
    digitalWrite(F, forward);
    digitalWrite(B, backward);
    digitalWrite(L, left);
    digitalWrite(R, right);
    
  }             
}
