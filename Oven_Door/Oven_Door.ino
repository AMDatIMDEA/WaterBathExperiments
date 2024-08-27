const int pinOpen = 4;
NEW SKETCH

const int pinClose = 5;
const int in1 = 2;  // direction of motor rotation 1
const int in2 = 3;  // direction of motor rotation 2
const int button = 4; // emergency stop
const int pinSensor = 8;  // position sensor

char command;

void setup() {
  pinMode(pinOpen, INPUT);
  pinMode(pinClose, INPUT);
  pinMode(pinSensor, INPUT);
  pinMode(button, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  digitalWrite(in1, LOW);   // IN1 to LOW
  digitalWrite(in2, LOW);   // IN2 to LOW

  Serial.begin(9600);   // Serial communication

}

void loop() {

  int sensorState = digitalRead(pinSensor);
  Serial.println(sensorState);    // 0 or 1
  delay(1000);

  int buttonState = digitalRead(button);

  if (Serial.available() > 0 && sensorState == LOW) {
    command = Serial.read();
   
   
    if (command == 'O') {
      openTheDoor();
    } else if (command == 'C') {
      Serial.println('C');
      closeTheDoor();
    } 
  } else if (Serial.available() > 0 && sensorState == HIGH){
    Serial.println("The door is closed");
    digitalWrite(command, LOW);
  }

  if (buttonState == HIGH) {    //emergency stop
    digitalWrite(in1, LOW);   
    digitalWrite(in2, LOW); }

}

void openTheDoor() {
  Serial.println("Opening the door");
  digitalWrite(in1, HIGH);  
  digitalWrite(in2, LOW);   
}

void closeTheDoor() {
  Serial.println("Closing the door");
  digitalWrite(in1, LOW);   
  digitalWrite(in2, HIGH);  
}

