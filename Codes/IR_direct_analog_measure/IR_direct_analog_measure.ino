#define ir A0
int nb_steps = 100;
boolean done = false;

void setup() {
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  delay(2000);
  
  if (done == false) {
    int avg_val = 0;
    int avg_val_square = 0;
    
    for (int n = 0; n < nb_steps; n++) {
      delay(50);   
      int val = analogRead(ir);
      Serial.println(val);
    }
    
  }
  
  done = true;
}
