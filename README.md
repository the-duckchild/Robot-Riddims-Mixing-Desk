````markdown
# Robot Riddims Mixing Desk

A 10-channel MIDI controller and mixing desk designed for hands-on music production and performance.
Each channel features two potentiometers, three latching buttons, and one momentary button, providing an expressive control surface for your DAW or hardware instruments.
The desk also includes Ableton Live scene control buttons and a dedicated, smooth master fader.

![RobotRiddims Mixing Desk Image](DSC-0725.jpg)

## Features

- **10 Independent Channels**
  - Each channel equipped with:
    - 2 Potentiometers (e.g., for volume, pan, FX sends)

    - 3 Latching Buttons (toggle mute, solo, record enable, etc.)
    - 1 Momentary Button (ideal for triggering samples/effects)
- **Global Controls**
  - Master fader for overall output control
  - Dedicated Ableton Live scene launch and navigation buttons
- **Class-compliant MIDI over USB**
  - Plug-and-play functionality with most operating systems and DAWs

## Project Goals

- Provide a flexible, tactile surface for modern music production and performance setups
- Support customizable MIDI mappings, allowing easy integration with various DAWs such as Ableton Live, Logic Pro, FL Studio, and hardware synths/samplers
- Reliable, hackable hardware and firmware for tinkerers and performers

## Hardware

- Built around a microcontroller supporting MIDI over USB (e.g., Arduino, Teensy, etc.)
- All components designed for durability and stage use
- Open schematic and build guide (coming soon!)

## Firmware

- **Current Version:** Custom firmware (originally based on [tttapa/MIDI_controller](https://github.com/tttapa/MIDI_controller), now replaced)
- Easily modifiable for new control schemes or hardware expansions

## Getting Started

1. **Build the Hardware:**  
   A full bill of materials (BOM), wiring diagram, and enclosure plans will be provided in the `docs/` directory (coming soon).

2. **Upload the Firmware:**  
   - Clone this repository.
   - Open the firmware code in your favorite Arduino IDE.
   - Flash it to your microcontroller.

3. **Connect & Map Controls:**  
   - Plug the desk into your computer or MIDI host via USB.
   - Open your DAW and assign the MIDI controls to desired parameters.

## Resources

- Original inspiration and library: [tttapa/MIDI_controller](https://github.com/tttapa/MIDI_controller)
- [Ableton Live MIDI mapping documentation](https://help.ableton.com/hc/en-us/articles/209775225-How-to-configure-MIDI-control-surfaces)
- [MIDI.org: Introduction to MIDI](https://www.midi.org/)

## Contributing

Pull requests, feature suggestions, and feedback are highly welcome! Please open an issue to discuss potential contributions or to request features.

## License

This project is open-source under the MIT License. See [`LICENSE`](LICENSE) for more information.

---
Enjoy building and making music with Robot Riddims Mixing Desk!
````
