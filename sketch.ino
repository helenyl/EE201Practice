// https://wokwi.com/projects/345981648474473042

#define LED 2 // LED on pin 2
#define POT A0 // Potentiometer on pin A0

void setup() {
  // put your setup code here, to run once:

  // Define whether the pins are inputs or outputs
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);

  // Start the serial monitor for printing
  // 9600 baud rate (speed) is sufficient
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potStatus = analogRead(POT);
  //Serial.println(potStatus);
  float delaytime;
  if (potStatus == 0) {
    delaytime = 5000;
  } else {
    delaytime = (1.0 / (potStatus)) * 200000;
  } 
  Serial.println(delaytime);

  digitalWrite(2, HIGH);
  delay(round(delaytime));
  digitalWrite(2, LOW);
  delay(round(delaytime));
}
