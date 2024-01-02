#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define keypad pin connections
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Define LCD display settings
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Calculator variables
String input = ""; // String to store user input
float num1 = 0; // First operand
float num2 = 0; // Second operand
char operatorSymbol = ' '; // Operator symbol
bool resultShown = false; // Flag to indicate if result is shown

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize LCD display
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Calculator");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Read keypad input
  char key = keypad.getKey();

  // If a key is pressed
  if (key != NO_KEY) {
    // Check if the result is shown, if so, clear the display
    if (resultShown) {
      lcd.clear();
      resultShown = false;
    }

    // Check if the key is a digit or a decimal point
    if (isdigit(key) || key == '.') {
      // Append the key to the input string
      input += key;
      lcd.print(key);
    }
    // Check if the key is an operator (+, -, *, /)
    else if (key == '+' || key == '-' || key == '*' || key == '/') {
      // Store the input string as the first operand
      num1 = input.toFloat();
      // Store the operator symbol
      operatorSymbol = key;
      // Reset the input string
      input = "";
      // Print the operator symbol on the LCD display
      lcd.setCursor(15, 0);
      lcd.print(operatorSymbol);
    }
    // Check if the key is the equals sign (=)
    else if (key == '=') {
      // Store the input string as the second operand
      num2 = input.toFloat();
      // Reset the input string
      input = "";
      // Perform the calculation based on the operator symbol
      float result;
      switch (operatorSymbol) {
        case '+':
          result = num1 + num2;
          break;
        case '-':
          result = num1 - num2;
          break;
        case '*':
          result = num1 * num2;
          break;
        case '/':
          result = num1 / num2;
          break;
        default:
          // Display error message if an invalid operator is used
          lcd.setCursor(0, 1);
          lcd.print("Error");
          delay(1000);
          lcd.clear();
          break;
      }
      // Print the result on the LCD display
            lcd.setCursor(0, 1);
      lcd.print("Result: ");
      lcd.print(result);
      resultShown = true;
    }
    // Check if the key is the 'C' key for clear
    else if (key == 'C') {
      // Clear the input string and reset the calculator
      input = "";
      num1 = 0;
      num2 = 0;
      operatorSymbol = ' ';
      resultShown = false;
      lcd.clear();
    }
  }
}