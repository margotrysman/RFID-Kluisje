
//add libraries
#include <SPI.h> //library used to communicate with SPI devices, like the RFID scanner
#include <MFRC522.h> //library used to work specifically with RFID readers

#define RST_PIN 9  //pin where RST > RFID is connected
#define SS_PIN 10  //pin where SPI SS > RFID is connected

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance using the necessary pins
byte accesUID2[7] = { 0x04, 0x27, 0x17, 0xE2, 0x3D, 0x75, 0x80 }; //create array consisting of bytes, with a starting value (each starting with 0x signifying them as individual bytes)
bool cardCorrect = false; //create a bool variable showing if the card is the correct one or not

void setup() {
  Serial.begin(115200);  // Initialize serial communications with the PC    
  SPI.begin();                        // Initiate SPI bus
  mfrc522.PCD_Init();                 // Initiate MFRC522
  delay(4);                           // Optional delay during startup
  mfrc522.PCD_DumpVersionToSerial();  // Dumps some info on the PCD and MFRC522 Card Reader, like version
  Serial.println(F("Ready to scan")); //additional feedback to show if setup was succesfull
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent()) { //! signifies if the opposite, so if a new card is NOT present
    return; //stops the current iteration of the loop and goes back to the start --> keeps trying to find a new card
  }
  else {
    Serial.println("New Card Found"); //if a new card is not not present, it must be present! Gives feedback as to this
  }


  if (!mfrc522.PICC_ReadCardSerial()) { //makes an attempt to read the UID of the card, returns if not succesfull
    Serial.println("Unable to read card UID"); //gives feedback if unsuccesfull
    return;
  }
  else {
    Serial.println("Data read"); //gives feedback if succesfull
  }
  
  if (memcmp(mfrc522.uid.uidByte, accesUID2, sizeof(mfrc522.uid.uidByte)) == 0) { 
    //memcmp compares two memory blocks, here bytes, and returns a 0 if identical and a positive or negative number otherwise
    //mfrc522.uid.uidByte refers to the uid read by the mfrc522 module, expressed in bytes (block 1 to compare)
    //accesUID2 is the previously defined correct uid to compare to (block 2 to compare)
    //comparison is done on the entire length of the mfrc522.uid.uidByte array, using sizeof()
    Serial.println("Correct card!"); //gives feedback on correct card
    cardCorrect = true; //changes parameter later used to activate the lock
}
else{
  cardCorrect = false; //ensures parameter is false when the UID is not correct in this iteration, even if it was in the past
}

Serial.println(cardCorrect); //prints the parameter just for extra feedback
mfrc522.PICC_HaltA(); //stops communicating with the card until it's removed and presented again
}
