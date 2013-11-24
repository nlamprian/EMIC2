// This example exposes some of the functionality of the EMIC2 library

#include <SoftwareSerial.h>  // Needed by the EMIC2 library
#include <SD.h>  // Needed by the EMIC2 library, though not utilized in this example
#include "EMIC2.h"

// Read here: http://arduino.cc/en/Reference/SoftwareSerial
// for the available pins on your board
#define RX_PIN 5  // Connect SOUT pin of the Emic 2 module to the RX pin
#define TX_PIN 6  // Connect SIN pin of the Emic 2 module to the TX pin

EMIC2 emic;  // Creates an instance of the EMIC2 library

void setup()
{
    // Initializes the EMIC2 instance
    // The library sets up a SoftwareSerial port
    // for the communication with the Emic 2 module
    emic.begin(RX_PIN, TX_PIN);
    
    emic.setVoice(8);  // Sets the voice (9 choices: 0 - 8)
}

void loop()
{
    // The speak method sends a message to the module
    // and then returns while the message plays on the module
    emic.speak("Welcome to the /\\/\\__EMIC2\\/\\/ library. This is an Arduino library \
                that simplifies the use of the __Emic __2 __Text __to __Speech __Module");
    emic.speak(":-)1 Let's now look at some ##pause of the features that the library offers");
    delay(2500);
    ~emic;  // Pauses playback
    delay(500);
    ~emic;  // Unpauses playback when paused
    
    // Sets the speaking rate to 100words/minute (range: [75,600])
    // and then resets it to 200words/minute
    emic.setRate(100);
    emic.speak("You can set and reset the speaking rate");
    emic.resetRate();
    
    // Increases the speaking rate by 150words/minute
    // and then decreases it by 150words/minute
    emic >> 150;
    emic.speak("You can change the speaking rate by the use of operators");
    emic << 150;
    
    // Sets the volume level to 15dB (range: [-48,18])
    // and then resets it to 0dB
    emic.setVolume(10);
    emic.speak("You can set and reset the volume level");
    emic.resetVolume();
    
    // Lowers the volume level by 10dB
    // and then raises it by 10dB
    emic -= 9;
    --emic;
    emic.speak("You can change the volume level by the use of operators");
    emic += 9;
    ++emic;
    
    emic.speak("You can provide any kind of data");
    emic.speak("Even doubles");
    emic.speak(3.14);  // It accepts various alphanumeric or numeric data types
    
    emic.speak(":-)0 Let's now sing a song");
    emic.speakDemo(1);
    delay(2000);
    !emic;  // Stops playback
    
    emic.speak("/\\/\\__DON'T EVEN THINK ABOUT IT");
    // Some of the texts above make use of special control symbols for dynamic changes of
    // pitch (/\ - increase, \/ - decrease), rate (>> - increase, << - decrease),
    // emphasis (__ - emphasize next word), whispering (## - whisper next word),
    // and voice (:-)x, x:[0,8])
    
    while (true) ;
}

