# Human Height Measurer with BMI Calculator

An Arduino-based project to accurately measure a person's height using an ultrasonic sensor and subsequently calculate their Body Mass Index (BMI). [cite_start]This was developed as a final project for the state-certified assistant degree in information technology at the David Roentgen Schule[cite: 2, 9].

[cite_start] [cite: 376]

## 📋 About the Project

[cite_start]The goal of this project was to develop a faster, more accurate, and more convenient alternative to traditional methods of measuring height, such as using a measuring tape[cite: 28]. [cite_start]It integrates a BMI calculator, as BMI is an important indicator of a person's health[cite: 29]. [cite_start]The device is designed to be user-friendly, allowing anyone to determine their height and BMI in under 1.5 minutes[cite: 263].

## ✨ Key Features

* [cite_start]**Height Measurement:** Utilizes an HC-SR04 ultrasonic sensor to measure the distance to a person's head and calculate their total height[cite: 276, 229].
* [cite_start]**BMI Calculation:** After the height is measured, the user can input their weight using buttons to calculate their BMI[cite: 35, 37]. The result is displayed on the screen.
* [cite_start]**LCD Display:** All information, including instructions, height, and BMI, is shown on a 20x4 character LCD display[cite: 34, 223].
* [cite_start]**Audio Feedback:** A Piezo buzzer provides an audible tone to confirm that a measurement has been successfully taken[cite: 32].
* [cite_start]**User Interface:** The device is operated with five push-buttons for starting the process, adjusting weight, and calculating the BMI[cite: 248, 249].
* [cite_start]**Custom Enclosure:** The components are housed in two custom-built enclosures made from durable HPL plates[cite: 356, 412].

## 🛠️ Hardware Components

The following components were selected for the final build:

* [cite_start]**Microcontroller:** Arduino Nano V3.0 [cite: 225]
* [cite_start]**Sensor:** HC-SR04 Ultrasonic Sensor [cite: 229]
* [cite_start]**Display:** 20x4 LCD Display with an I2C Interface [cite: 223]
* [cite_start]**Buttons:** 4-Pin Push-button Switches [cite: 230]
* [cite_start]**Buzzer:** KY-006 Passive Piezo Buzzer [cite: 233]
* [cite_start]**Prototyping:** Breadboard and Jumper Wires [cite: 234]
* [cite_start]**Enclosure:** 15mm thick HPL plates [cite: 241, 356]

## ⚙️ How It Works

1.  [cite_start]**Setup:** The sensor box is mounted above a doorway at a fixed height of 226 cm[cite: 31]. [cite_start]The main box with the LCD and buttons is placed next to the door at eye level[cite: 36].
2.  [cite_start]**Measurement:** The user presses the "Start" button and is prompted to stand underneath the ultrasonic sensor[cite: 246, 363].
3.  [cite_start]**Calculation:** The sensor emits an ultrasonic wave, measures the time it takes for the echo to return, and calculates the distance to the user's head[cite: 276, 279]. [cite_start]The person's height is then determined by subtracting this distance from the sensor's fixed height (226 cm)[cite: 33, 297].
4.  **Weight Input:** The measured height appears on the LCD screen. [cite_start]The user is then prompted to enter their weight using the "Up" and "Down" buttons[cite: 35, 249].
5.  [cite_start]**BMI Display:** After confirming the weight, the device calculates the BMI using the formula: $$BMI = \frac{weight(kg)}{height(m)^2}$$ [cite: 37] and displays the result.

## 👤 Author

* **Loran Demiroglu**
* [cite_start]**Email:** lorandemiroglu04@gmail.com [cite: 13]
