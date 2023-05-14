
// LIBRARIES
#include <SPI.h>
#include <RF24.h>
#include <NewPing.h>


// Ultrasonic sensor 4
NewPing sonar(3, 4);

// NRF module
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001"; 

void setup() {
   
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  analogWrite(5, 0); 
  analogWrite(6, 0);
  
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address); // Set the address to send data to add

}

void loop() {
  
  unsigned int distance = sonar.ping_cm();
  analogWrite(5, 100); 
  analogWrite(6, 100);
  //Obstacle detection 
  if (distance < 25) {
    const char* message = "An obstacle was detected!";
    radio.write(message, strlen(message));
    Serial.println("Transmitted message: Obstacle detected!");

    analogWrite(5, 0); // Turn off left motor
    analogWrite(6, 0); // Turn off right motor
    delay(1000); // Wait for motors to stop
    
    analogWrite(5, 105); // Turn ON left motor
    analogWrite(6, 0); // Turn OFF right
    delay(1700); // Turn for 1 second

    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); 
    
    analogWrite(5, 105); // Move forward
    analogWrite(6, 100);
    delay(1300); // Move forward for 1 second
    
    analogWrite(5, 0); // Turn off left motor
    analogWrite(6, 0); // Turn off right motor
    delay(1000); // Wait for motors to stop
    
    analogWrite(5, 0);
    analogWrite(6, 100);//TURN LEFT
    delay(1700); // Turn for 1 second

    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); // Move forward for 1 second
    
    analogWrite(5, 105); // Move forward again
    analogWrite(6, 100);
    delay(1700); // Move forward for 1 second

    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); // 
    
    analogWrite(5, 0); // Turn LEFT
    analogWrite(6, 100);
    delay(1700);
    
    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); 
    
    analogWrite(5, 105); // Move forward
    analogWrite(6, 100);
    delay(1300);
  
     
    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); 
    
    analogWrite(5, 105); // TURN RIGHT
    analogWrite(6, 0);
    delay(1700);

    
    analogWrite(5, 0); // STOP
    analogWrite(6, 0);
    delay(1000); 
    
    analogWrite(5, 105); // Move forward
    analogWrite(6, 100);
    delay(1000);
  }

  // Wait before next check
  delay(500);
}
