
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9  // Configurable, see typical pin layout above
#define SS_PIN 10  // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
byte accesUID2[7] = { 0x04, 0x27, 0x17, 0xE2, 0x3D, 0x75, 0x80 };

#include <Servo.h>
Servo myServo; // Create servo object to control a servo motor
int servoPin=8;

int count =0;

void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC                       // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  while (!Serial)
    ;
  SPI.begin();                        // Init SPI bus
  mfrc522.PCD_Init();                 // Init MFRC522
  delay(4);                           // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  myServo.attach(servoPin); // Attach the servo to pin 9
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent()) {
    Serial.println("kaart gedetecteerd");
    delay(500);
    return;
  }

  // while niet juiste volgorde
  if (!mfrc522.PICC_ReadCardSerial()) {
    Serial.println("kaart ingelezen");
    return;
  }

  if (mfrc522.uid.uidByte[0] == accesUID2[0] && mfrc522.uid.uidByte[1] == accesUID2[1] && mfrc522.uid.uidByte[2] == accesUID2[2] && mfrc522.uid.uidByte[3] == accesUID2[3] && mfrc522.uid.uidByte[4] == accesUID2[4] && mfrc522.uid.uidByte[5] == accesUID2[5] && mfrc522.uid.uidByte[6] == accesUID2[6]) {
    Serial.println("Correct");
    delay(500);
    //als even dan draai ene hoek
    //als oneven draai andere hoek
    if ((count%2)==0){
      myServo.write(90);
    }
    if((count%2)!=0){
      myServo.write(0);
    }
    count+=1;
  }


  mfrc522.PICC_HaltA();
  // Dump debug info about the card; PICC_HaltA() is automatically called
}
