int potPin = A2;
int hdmiOneLED = 2;
int hdmiTwoLED = 3;
int hdmiOneBTN = 4;
int hdmiTwoBTN = 5;

int value;
int btnStatus = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(hdmiOneLED, OUTPUT);
  pinMode(hdmiTwoLED, OUTPUT);
  pinMode(hdmiOneBTN, INPUT);
  pinMode(hdmiTwoBTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(potPin);
  Serial.println(value);

  if (buttonPressed(hdmiOneBTN) || btnStatus == 0) {
    digitalWrite(hdmiOneLED, HIGH);
    digitalWrite(hdmiTwoLED, LOW);
    btnStatus = 0;
    //send serial output
  }

  if (buttonPressed(hdmiTwoBTN) || btnStatus == 1) {
    digitalWrite(hdmiTwoLED, HIGH);
    digitalWrite(hdmiOneLED, LOW);
    btnStatus = 1;
  }

//  if (digitalRead(hdmiOneBTN) == HIGH && btnStatus == 0) {
//    digitalWrite(hdmiOneLED, HIGH);
//    digitalWrite(hdmiTwoLED, LOW);
//    btnStatus = 0;
//  }
//
//  if (digitalRead(hdmiTwoBTN) == HIGH && btnStatus == 1) {
//    digitalWrite(hdmiTwoLED, HIGH);
//    digitalWrite(hdmiOneLED, LOW);
//    btnStatus = 1;
//  }
//  
}

int buttonPressed(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
