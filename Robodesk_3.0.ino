#include <Encoder.h>
 
#include <MIDI_Controller.h>
      //Midi controller library

#include <ResponsiveAnalogRead.h>
      // analog smoothing
     
#include <Bounce.h>
      // include the Bounce library for 'de-bouncing' switches -- removing electrical chatter as contacts settle
      // usbMIDI.h library is added automatically when code is compiled as a MIDI device

using namespace ExtIO;
     // use standard arduino digital write pin mode etc. 


AnalogMultiplex buttonsmux1(1, { 10, 11, 12 } );
AnalogMultiplex buttonsmux2(0, { 10, 11, 12 } );
AnalogMultiplex Ledbuttonsmux1(2, { 10, 11, 12 } );
AnalogMultiplex Ledbuttonsmux2(3, { 10, 11, 12 } );
AnalogMultiplex Ledbuttonsmux3(4, { 10, 11, 12 } );
AnalogMultiplex Ledbuttonsmux4(5, { 10, 11, 12 } );
AnalogMultiplex fadersmux1(A0, { 10, 11, 12 } );
AnalogMultiplex faderspotsmux (A1, { 10, 11, 12 } );
AnalogMultiplex potsmux1 (A2, { 10, 11, 12 } );
AnalogMultiplex potsmux2 (A3, { 10, 11, 12 } );

     // creating muxers
     //AnalogMultiplex(pin_t analogPin, { pin_t addressPin1, addressPin2, ... addressPinN } )
     //analogPin: the analog input pin connected to the output of the multiplexer
     //addressPin#: the digital output pins connected to the address lines of the multiplexer


DigitalLatch Arcadebuttons[] = {
  {buttonsmux1.pin(0), 0, 14, 127, 10},
  {buttonsmux1.pin(1), 1, 14, 127, 10},
  {buttonsmux1.pin(2), 2, 14, 127, 10},
  {buttonsmux1.pin(3), 3, 14, 127, 10},
  {buttonsmux1.pin(4), 4, 14, 127, 10},
  {buttonsmux1.pin(5), 5, 14, 127, 10},
  {buttonsmux1.pin(6), 6, 14, 127, 10},
  {buttonsmux1.pin(7), 7, 14, 127, 10},
     // Create 8 new instances of the class 'DigitalLatch', on the 8 pins of the buttonsmux1
     // that send MIDI notes  0-7 on channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 
     
};

DigitalLatch Arcadebuttonextras[] = {
  {buttonsmux2.pin(3), 8, 14, 127, 10},
  {buttonsmux2.pin(4), 9, 14, 127, 10},
     //extra two arcade buttons
     // that send MIDI notes  8 & 9 on channel 14
     
};

Digital Navigation[] = {
  {buttonsmux2.pin(5), 10, 14, 127},
  {buttonsmux2.pin(6), 11, 14, 127},
  {buttonsmux2.pin(7), 12 , 14, 127},
      // Create 3 new instances of the class 'Digital' for navigation buttons, on the 3 pins of the buttonsmux2
     // that send MIDI notes 10-12 on channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 
     
};

Analog MasterFader (A9, 19, 14);

Analog Faders1[] = {
  {fadersmux1.pin(0), 20, 14},
  {fadersmux1.pin(1), 21, 14},
  {fadersmux1.pin(2), 22, 14},
  {fadersmux1.pin(3), 23, 14},
  {fadersmux1.pin(4), 24, 14},
  {fadersmux1.pin(5), 25 , 14},
  {fadersmux1.pin(6), 26, 14},
  {fadersmux1.pin(7), 27, 14},
       //create 8 new instances of the class "Analog" for the first 8 channel faders, on the 3 pins of fadersmux1
       // that send CC commands 20-27 on MIDI channel 14
       // Analog(pin_t analogPin, uint8_t controllerNumber, uint8_t channel)

};

  Analog FadersPots[] = {
  {faderspotsmux.pin(0), 28, 14},
  {faderspotsmux.pin(1), 29, 14},
  {faderspotsmux.pin(2), 30, 14},
  {faderspotsmux.pin(3), 31, 14},
  {faderspotsmux.pin(4), 32, 14},
  {faderspotsmux.pin(5), 33, 14},
  {faderspotsmux.pin(6), 34, 14},
  {faderspotsmux.pin(7), 35, 14},
       //create 8 new instances of the class "Analog" for faders 8&9 and six leftmost pots, on the 3 pins of faderspotmux
       // that send CC commands 28-35 on MIDI channel 14
       // Analog(pin_t analogPin, uint8_t controllerNumber, uint8_t channel)

};

  Analog Pots1[] = {
  {potsmux1.pin(0), 36, 14},
  {potsmux1.pin(1), 37, 14},
  {potsmux1.pin(2), 38, 14},
  {potsmux1.pin(3), 39, 14},
  {potsmux1.pin(4), 40, 14},
  {potsmux1.pin(5), 41, 14},
  {potsmux1.pin(6), 42, 14},
  {potsmux1.pin(7), 43, 14},
       //create 8 new instances of the class "Analog" for the middle section of pots, on the 3 pins of faderspotmux
       // that send CC commands 36-43 on MIDI channel 14
       // Analog(pin_t analogPin, uint8_t controllerNumber, uint8_t channel)

};

  Analog Pots2[] = {
  {potsmux2.pin(0), 44, 14},
  {potsmux2.pin(1), 45, 14},
  {potsmux2.pin(2), 46, 14},
  {potsmux2.pin(3), 47, 14},
  {potsmux2.pin(4), 48, 14},
  {potsmux2.pin(5), 49, 14},
  {potsmux2.pin(6), 50, 14},
  {potsmux2.pin(7), 51, 14},
       //create 8 new instances of the class "Analog" for the middle section of pots, on the 3 pins of faderspotmux
       // that send CC commands 36-43 on MIDI channel 14
       // Analog(pin_t analogPin, uint8_t controllerNumber, uint8_t channel)

};

DigitalLatch Ledbuttons1 [] = {
  {Ledbuttonsmux1.pin(0), 13, 14, 127, 10},
  {Ledbuttonsmux1.pin(1), 14, 14, 127, 10},
  {Ledbuttonsmux1.pin(2), 15, 14, 127, 10},
  {Ledbuttonsmux1.pin(3), 16, 14, 127, 10},
  {Ledbuttonsmux1.pin(4), 17, 14, 127, 10},
  {Ledbuttonsmux1.pin(5), 18, 14, 127, 10},
  {Ledbuttonsmux1.pin(6), 19, 14, 127, 10},
  {Ledbuttonsmux1.pin(7), 20, 14, 127, 10},
     // create 8 new instance of the class "Digital" for the right hand 8 LED buttons on the pins of Ledbuttonsmux1
     // They send notes 13-20 on MIDI channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 

};

DigitalLatch Ledbuttons2 [] = {
  {Ledbuttonsmux2.pin(0), 21, 14, 127, 10},
  {Ledbuttonsmux2.pin(1), 22, 14, 127, 10},
  {Ledbuttonsmux2.pin(2), 23, 14, 127, 10},
  {Ledbuttonsmux2.pin(3), 24, 14, 127, 10},
  {Ledbuttonsmux2.pin(4), 25, 14, 127, 10},
  {Ledbuttonsmux2.pin(5), 26, 14, 127, 10},
  {Ledbuttonsmux2.pin(6), 27, 14, 127, 10},
  {Ledbuttonsmux2.pin(7), 28, 14, 127, 10},
     // create 8 new instance of the class "Digital" for the right hand 8 LED buttons on the pins of Ledbuttonsmux1
     // They send notes 21-28 on MIDI channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 

};


DigitalLatch Ledbuttons3 [] = {
  {Ledbuttonsmux3.pin(0), 29, 14, 127, 10},
  {Ledbuttonsmux3.pin(1), 30, 14, 127, 10},
  {Ledbuttonsmux3.pin(2), 31, 14, 127, 10},
  {Ledbuttonsmux3.pin(3), 32, 14, 127, 10},
  {Ledbuttonsmux3.pin(4), 33, 14, 127, 10},
  {Ledbuttonsmux3.pin(5), 34, 14, 127, 10},
  {Ledbuttonsmux3.pin(6), 35, 14, 127, 10},
  {Ledbuttonsmux3.pin(7), 36, 14, 127, 10},
     // create 8 new instance of the class "Digital" for the right hand 8 LED buttons on the pins of Ledbuttonsmux1
     // They send notes 29-36 on MIDI channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 

};

DigitalLatch Ledbuttons4 [] = {
  {Ledbuttonsmux4.pin(2), 37, 14, 127, 10},
  {Ledbuttonsmux4.pin(3), 38, 14, 127, 10},
  {Ledbuttonsmux4.pin(4), 39, 14, 127, 10},
  {Ledbuttonsmux4.pin(5), 40, 14, 127, 10},
  {Ledbuttonsmux4.pin(6), 41, 14, 127, 10},
  {Ledbuttonsmux4.pin(7), 42, 14, 127, 10},
     // create 6 new instance of the class "Digital" for the right hand 8 LED buttons on the pins of Ledbuttonsmux1
     // They send notes 37-42 on MIDI channel 14
     //Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity = 127, latch time)
     //pin: the digital input pin to read the state from, the internal pull-up resistor will be enabled
     //note: the MIDI note number [0, 127]
     //channel: the MIDI channel [1, 16]
     //velocity: the MIDI velocity of the Note events [1, 127], how hard the key/button is struck 

};
  
//CONSTANT VALUES

  const static byte Channel_Volume = 0x7; 
     // controller number 7 is defined as Channel Volume in the MIDI implementation.
  const static size_t analogAverage = 8; 
     // Use the average of 8 samples to get smooth transitions and prevent noise
  const static byte velocity = 127; 
     // the maximum velocity, since MIDI uses a 7-bit number for velocity.
  const static int  latchTime = 3000;  
     // the amount of time (in ms) the note is held on. Read documentation or see source code for more information.
  const static byte C4 = 60; 
     // note number 60 is defined as middle C in the MIDI implementation.
  const static byte E0 = 16; 
    // note number 60 is defined as middle C in the MIDI implementation, so 16 is E0
  const byte Channel = 14; 
     // MIDI channel 14
  const byte Controller = 0x14; 
     // MIDI controller number
  const int speedMultiply = 1; 
      // no change in speed of the encoder
      

void setup() {

}      
void loop() {

MIDI_Controller.refresh();
}

     
