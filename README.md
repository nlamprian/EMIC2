EMIC2
=====

Wow, what can I say about the [Emic 2 Text-to-Speech](http://www.grandideastudio.com/portfolio/emic-2-text-to-speech-module/) module... this very well designed and simple to use piece of hardware. I would say `Εμεινα μαλάκας`, but it would probably sound all greek to you, so I won't. I will rather say that I had the most fun experimenting with this module, and I would be happy to do it again.

Now, to the point... This is an Arduino library for interfacing the [Emic 2 Text-to-Speech](http://www.grandideastudio.com/portfolio/emic-2-text-to-speech-module/) module. With the library, one can change the characteristics of the speech on the module through the use of methods and operators, for a less technical and more natural way of control. It can send messages provided as an immediate argument to a method, or by reference through a file in an SD card.

![emic2](http://i859.photobucket.com/albums/ab154/lampnick67/emic2__zpsf8ec194d.png)

Interface
---------

An instance of the EMIC2 class has to have been created before utilizing the Emic 2 module. Then the instance gets initialized by calling `begin(uint8_t rx_pin, uint8_t tx_pin, uint8_t cs_pin)` with arguments the `RX` and `TX` pins of the (software) serial port, and optionally the `CS` pin for the chip select line of the SD card.

The class provides, among others, methods for setting the voice, the language, and the parser. It also provides methods for tweaking parameters that are independent of the choice of parser, such as volume and speaking rate.

Parameters that are dependent to the choice of parser can be looked at the [manual](http://parallax.com/sites/default/files/downloads/30016-Emic-2-Text-To-Speech-Documentation-v1.1.pdf), and set by sending a direct command to the module, by using the `sendCmd` method.

A message can be sent by calling the `speak` method on an instance of the class, with argument any type of data. (e.g. `emic.speak("I'm the Emic 2 Module");`)

The `speak` method can also read files from an SD Card. By providing a filename as an argument, the method will read the file in the `emic2` folder (that you will have to have created) and it will send a message to the Emic 2 module for every line in the file. (e.g. `emic.speak("greeting.txt",SD_C);`)

Special use of operators, that they act upon an instance of the class, can further simplify the process of interfacing with the module:
* `~emic;` - pauses/unpauses playback
* `!emic;` - stops playback
* `++emic;` - raises volume level by 1dB
* `--emic;` - lowers volume level by 1dB
* `emic += value;` - raises volume level by `value` dB
* `emic -= value;` - lowers volume level by `value` dB
* `emic >> value;` - increases speaking rate by `value` words/minute
* `emic << value;` - decreases speaking rate by `value` words/minute

Examples
--------
There are two accompanying example sketches, `SpeakMessage` and `SpeakMsgFromSD`, that expose some of the functionality of the library.
