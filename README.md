# GSM-Based-Voltage-Alert-System-using-Arduino-SIM800L
This project monitors voltage using a potentiometer connected to an Arduino. When the voltage reaches 4.8V or higher, the system automatically sends an SMS and makes a phone call using the SIM800L GSM module. This is useful for voltage-based alert systems like power monitoring, battery protection, or trigger-based alerts.

 Components Required
Component	Quantity
Arduino UNO/Nano	1
SIM800L GSM Module	1
Potentiometer (10k)	1
Power Supply (External 5V/3.7V for SIM800L)	1
Breadboard & Jumper Wires	As needed

SIM800L Pin	Connect To
VCC	3.7V – 4.2V Battery or 5V via diode (⚠️ Not 5V Arduino)
GND	GND
TX	Arduino Pin 7 (RX of SoftwareSerial)
RX	Arduino Pin 8 (TX of SoftwareSerial)

Arduino Pin	Connected To
A0	Potentiometer output
5V, GND	Potentiometer VCC/GND

Note: Use level shifter/resistor divider (1kΩ + 2kΩ) on TX if needed to protect SIM800L RX from 5V.

💻 Serial Monitor Output
text
Copy
Edit
Initializing GSM...
Sending: AT
OK
Sending: AT+CPIN?
READY
Sending: AT+CREG?
+CREG: 0,1
Sending: AT+CSQ
+CSQ: 20,0
Sending: AT+CMGF=1
OK
Voltage: 4.92
Sending SMS...
Dialing...
Hung up call.
