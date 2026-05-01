### Buttons & Controls
- [x] **SW1**: Activate the spacebar servo (jump) when pressed.
- [x] **SW2**: Activate the down arrow servo (duck) when pressed.
- [x] **SW3**: Reset the score to zero when pressed.
- [x] **Microcontroller Keypad**: Configure two keys to replicate SW1 and SW2 behaviors.

### Game Logic & Scoring
- [x] **Score Start**: Start score incrementation at the first spacebar press (after a reset).
- [x] **Incrementation**: Increase score at a rate of 10 points per second.

### Visual Outputs (LEDs & LCD)
- [x] **LED 1 & LED 2**: Turn on when the dinosaur jumps.
- [x] **LED 3 & LED 4**: Turn on when the dinosaur ducks.
- [x] **Reset Visual**: 3 LED flashes on reset.
- [x] **LCD Screen (Part 1)**: Display "Jump" during a jump and "Duck" during a duck.
- [x] **LCD Screen (Part 2)**: Display the current game score.

### Audio Output
- [x] **Jump Sound**: Emit a specific sound when the dinosaur jumps.
- [x] **Duck Sound**: Emit a different sound when the dinosaur ducks.
- [x] **Reset Audio**: 3 beeps on reset.

### Sensors (Photoresistors)
- [x] **Ground Sensor**: Configure photoresistor to detect ground obstacles.
- [x] **Air Sensor**: Configure photoresistor to detect flying obstacles.

### Serial Communication (UART)
- [x] **PC -> Board**: Detect "jump" and "duck" commands to activate servos (e.g., to start game).
- [x] **Board -> PC**: Send "Jump" message to serial monitor when the dinosaur jumps.
- [x] **Board -> PC**: Send "Duck" message to serial monitor when the dinosaur ducks.
- [x] **Error Handler**: Implement error handling for UART communication.
- [x] **Reset Command**: Implement reset command function via serial.