#include <SoftwareSerial.h>

SoftwareSerial gsm(7, 8); // RX (to TX of GSM), TX (to RX of GSM)
const int potPin = A0;
bool actionDone = false; // To prevent repeating actions

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  delay(3000); // Allow GSM module to stabilize

  Serial.println("Initializing GSM...");
  sendCommand("AT");         // Test GSM
  sendCommand("AT+CPIN?");   // Check SIM
  sendCommand("AT+CREG?");   // Network registration
  sendCommand("AT+CSQ");     // Signal strength
  sendCommand("AT+CMGF=1");  // Set SMS text mode
}


void loop() {
  int potValue = analogRead(potPin);
  float voltage = (potValue / 1023.0) * 5.0;

  Serial.print("Voltage: ");
  Serial.println(voltage, 2);

  if (voltage >= 4.8 && !actionDone) {
    sendSMS();
    delay(5000); // wait before call
    makeCall();
    actionDone = true;
  }

  delay(2000);
}

void sendSMS() {
  Serial.println("Sending SMS...");
  gsm.println("AT+CMGS=\"91********\""); // Your number
  delay(1000);
  gsm.println("Alert! Voltage reached 5V.");
  delay(500);
  gsm.write(26); // Ctrl+Z to send SMS
  delay(5000);
  readGSM();
}

void makeCall() {
  Serial.println("Dialing...");
  gsm.println("ATD91**********;"); // Your number
  delay(15000); // Let it ring 15 seconds
  gsm.println("ATH"); // Hang up
  Serial.println("Hung up call.");
  delay(1000);
  readGSM();
}

void sendCommand(String cmd) {
  Serial.print("Sending: ");
  Serial.println(cmd);
  gsm.println(cmd);
  delay(1000);
  readGSM();
}

void readGSM() {
  while (gsm.available()) {
    Serial.write(gsm.read());
  }
}
