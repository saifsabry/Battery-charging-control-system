# Battery Charging Controller

## Description
This Arduino-based Battery Charging Controller is designed to automate the battery charging process through multiple charge and discharge cycles. The system uses relays to control charging circuits and includes an LCD display interface for user interaction.

## Features
- Simple one-button interface for starting the charging program
- LCD display for viewing charging status and elapsed time
- Multiple charging and shorting cycles to optimize battery conditioning
- Automated timing sequence for different charging stages
- Visual LED indicator when charging process is complete

## Hardware Requirements
- Arduino board (Uno or similar)
- 16x2 LCD display
- 2 Relays (for controlling charging circuit and shorting circuit)
- Pushbutton for user input
- LED indicator
- Appropriate power supply for charging circuit
- Battery charging circuit (not included in code)

## Pin Configuration
- LCD: pins 12, 11, 5, 4, 3, 2
- Button: A0
- Charging Relay: pin 8
- Shorting Relay: pin 7
- Status LED: pin 2

## Operation Sequence
1. Press button to start the charging program
2. Sequence of operation:
   - Stage 1: Charging for 10 seconds (simulating 1 hour charge)
   - Stage 2: Short circuit discharge for 10 seconds
   - Stage 3: Charging for 10 seconds (simulating 2 hour charge)
   - Stage 4: Short circuit discharge for 10 seconds
   - Stage 5: Final charging for 10 seconds (simulating 12 hour charge)
   - Stage 6: Complete - all relays off and LED indicator on

## Note
This is a demonstration version with accelerated timing for testing purposes. In a production environment, the timing values should be adjusted to actual charging requirements (hours instead of seconds).

## Installation
1. Connect the hardware according to the pin configuration
2. Upload the sketch to your Arduino board
3. Power the Arduino and the charging circuit

## Usage
1. Turn on the device
2. The LCD will display "Charging Prog" with "Start" option
3. Press the button to begin the charging sequence
4. Monitor the progress on the LCD display
5. When complete, the "Done charging" message will appear

## Customization
To modify the charging times for real-world application, adjust the timing conditions in the `timer_min()` function. The current code uses seconds as a demonstration, but should be adjusted to appropriate hour values for actual battery charging.
