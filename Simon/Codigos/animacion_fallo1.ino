int LED1 = 8;
int LED2 = 12;
int LED3 = 13;
int LED4 = 7;
int LED5 = 4;
int LED6 = 2;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED1, HIGH); 
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH); 
    digitalWrite(LED6, HIGH);
    delay(500);   
    
    digitalWrite(LED1, HIGH); 
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, LOW);
    delay(500);   
    
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH); 
    digitalWrite(LED6, LOW);
    delay(500);  
    
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW); 
    digitalWrite(LED6, HIGH);
    delay(500);   
    
    digitalWrite(LED1, LOW);  
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);  
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);  
    digitalWrite(LED6, LOW);
    delay(500);                    
  }
  
  delay(1500); 
}