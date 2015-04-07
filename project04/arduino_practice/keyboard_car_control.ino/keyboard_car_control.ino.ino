void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read incoming serial data:
    char command = Serial.read();
    
    
    if(command == 'd') {
      Serial.println("Move forward");
      for(int i = 0; i < 1; i++) {
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);  
        digitalWrite(13, LOW);   // turn the LED off (LOW is the voltage level)
        delay(500); 
      }
    }
    else if(command == 's') {
      Serial.println("Move backwards");
      for(int i = 0; i < 4; i++) {
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);  
        digitalWrite(13, LOW);   // turn the LED off (LOW is the voltage level)
        delay(500); 
      }
    }
    else if(command == 'a') {
      Serial.println("Move left");
      for(int i = 0; i < 2; i++) {
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);  
        digitalWrite(13, LOW);   // turn the LED off (LOW is the voltage level)
        delay(500); 
      }
    }
    else if(command == 'f') {
      Serial.println("Move right");
      for(int i = 0; i < 3; i++) {
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);  
        digitalWrite(13, LOW);   // turn the LED off (LOW is the voltage level)
        delay(500); 
      }
    }
    else {
      //
    }
  }             
}
