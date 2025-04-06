# Electronic Calculator using Arduino

## Project Description
The **Electronic Calculator using Arduino** is a simple yet functional calculator that can perform basic arithmetic operations such as addition, subtraction, multiplication, and division. The project utilizes an **Arduino microcontroller**, a **4x4 keypad** for user input, and an **LCD display** to show the results. The goal of this project is to demonstrate how microcontrollers can be used for real-time computation and user interaction.

## Features
- Performs basic arithmetic operations: Addition, Subtraction, Multiplication, and Division.
- User-friendly interface with a 4x4 keypad.
- Displays real-time input and output on an LCD screen.
- Compact and portable design.
- Can be powered via USB or external battery.

## Components Used
- Arduino (Uno, Mega, or Nano)
- 4x4 Keypad
- 16x2 LCD Display (with I2C module for easy interfacing)
- Connecting Wires
- Breadboard
- Power Source (USB/Battery)

## Circuit Diagram
The circuit consists of:
1. The **4x4 Keypad** connected to Arduino digital pins.
2. The **16x2 LCD Display** connected via I2C module to the Arduino.
3. The **Arduino board** as the processing unit, handling user input and displaying results.

## Working Principle
1. The user inputs numbers and selects an operation (+, -, *, /) via the keypad.
2. The Arduino processes the input, performs the computation, and displays the result on the LCD.
3. The user can reset the calculator to perform a new calculation.

## Installation & Setup
1. Connect the components as per the circuit diagram.
2. Install the necessary Arduino libraries:
   - `Keypad.h` (for handling keypad input)
   - `LiquidCrystal_I2C.h` (for LCD display control)
3. Upload the Arduino code to the microcontroller using the Arduino IDE.
4. Open the Serial Monitor (optional) to debug and view real-time operations.

## How to Use
1. Power the Arduino board.
2. Use the keypad to enter numbers and select an operation.
3. Press `=` (equals key) to calculate and view the result on the LCD.
4. Press `C` (clear key) to reset the calculator.

## Applications
- Educational tool for learning embedded systems and Arduino programming.
- Simple calculator for DIY electronics projects.
- Basis for more advanced projects like scientific calculators or touchscreen-based systems.

## Future Enhancements
- Adding support for scientific calculations (square root, exponentiation, trigonometric functions).
- Implementing a touchscreen interface.
- Storing past calculations in EEPROM for history tracking.

## Conclusion
This **Electronic Calculator using Arduino** is a great project for beginners interested in embedded systems and microcontroller programming. It provides hands-on experience with Arduino, keypad interfacing, and LCD display handling.

## Author
Bawar Husain

## License
This project is open-source and can be modified and distributed freely for educational and personal use.