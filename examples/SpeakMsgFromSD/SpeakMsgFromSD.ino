// This example exposes the use of an SD card with the EMIC2 library
// Text files will be fetched from the SD card, read and sent to the Emic 2 module
// Steps:
// * Format an SD card to a FAT file system on your computer
// * Create a folder with name "emic2"
// * Create two text files with contents: (1) Hello Stranger, I'm the emic 2 text to speech module.
//                                            How can I be of service to you?
//                                        (2) Right away!
// The final arrangement will be /emic2/
//                                  |----> text001.txt
//                                  |----> text002.txt
// Notes:
// * The files can have at most 1023 characters per line
// * The filename of the files can be at most 8 characters (8.3 format)

#include <SoftwareSerial.h>  // Needed by the EMIC2 library
#include <SD.h>  // Needed by the EMIC2 library
#include "EMIC2.h"

// Read here: http://arduino.cc/en/Reference/SoftwareSerial
// for the available pins on your board
#define RX_PIN 5  // Connect SOUT pin of the Emic 2 module to the RX pin
#define TX_PIN 6  // Connect SIN pin of the Emic 2 module to the TX pin

// Chip Select pin for the SD card
// For more info http://arduino.cc/en/Reference/SD/
#define CS_PIN 4

EMIC2 emic;  // Creates an instance of the EMIC2 library

void setup()
{
    // Initializes the EMIC2 instance
    // The library sets up a SoftwareSerial port
    // for the communication with the Emic 2 module
    emic.begin(RX_PIN, TX_PIN, CS_PIN);
    emic += 10;
}

void loop()
{
    // The speak method fetches a file from the SD card
    // and creates one message per line of the file that gets sent to the Emic 2 module
    // Only the filename needs to be provided (file is inside the emic2 folder)
    emic.speak("text001.txt", SD_C);
    emic.ready();  // Waits until playback finishes
    delay(2000);
    emic.speak("text002.txt", SD_C);

    emic.setDefaultSettings();  // Restores all settings to their default values
  
    while (true) ;
}

