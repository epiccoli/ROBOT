
String command = ""; // Stores response of the HC-06 Bluetooth device


void setup() {
  // Open serial communications:
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  
  // The HC-06 defaults to 9600 according to the datasheet.
  Serial2.begin(115200);
}

void loop() {
  // Read device output if available.
  if (Serial2.available()) {
    while(Serial2.available()) { // While there is more to be read, keep reading.
      command += (char)Serial2.read();
    }
    
    Serial.println(command);
    command = ""; // No repeats
  }
  
  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    Serial2.write(Serial.read());
  }
}
