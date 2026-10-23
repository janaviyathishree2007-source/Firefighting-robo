# Firefighting-robo
🔥 Arduino Fire-Fighting Robot

An Arduino-based autonomous fire-fighting robot that detects flames using IR flame sensors, moves toward the detected fire, activates a water pump, and uses an ultrasonic sensor to avoid obstacles.

📌 Project Overview

This project is designed to demonstrate an autonomous fire-fighting robot using an Arduino-compatible microcontroller.

The robot uses:

- 🔥 3 IR flame sensors to detect the direction of fire
- 🚗 L298N motor driver to control two DC motors
- 💧 Water pump to extinguish the fire
- 🔄 Servo motor to move the water nozzle
- 📡 Ultrasonic sensor to detect obstacles
- 🔊 Buzzer for fire/obstacle alerts

The robot continuously monitors the flame sensors and adjusts its movement based on the detected fire direction.

⚙️ Components Required

- Arduino board
- L298N motor driver
- 2 × DC motors
- 3 × IR flame sensors
- HC-SR04 ultrasonic sensor
- Servo motor
- Water pump
- Buzzer
- Battery/power supply
- Water container
- Robot chassis
- Connecting wires

🔌 Pin Configuration

Component| Arduino Pin
L298N Enable A| D2
Motor 1 IN1| D3
Motor 1 IN2| D4
Motor 2 IN3| D5
Motor 2 IN4| D6
L298N Enable B| D7
Buzzer| D8
Ultrasonic Trig| D9
Ultrasonic Echo| D10
Left Flame Sensor| A0
Front Flame Sensor| A1
Right Flame Sensor| A2
Pump| A3
Servo| A4

🧠 Working Principle

The robot continuously reads the three flame sensors:

- Right sensor (A2) detects fire on the right.
- Front sensor (A1) detects fire in front.
- Left sensor (A0) detects fire on the left.

Based on the sensor readings, the robot changes its movement.

🔥 Fire Detected

When a flame is detected:

1. The robot stops.
2. The buzzer is activated briefly.
3. The water pump is activated.
4. The servo moves the nozzle to spray water across the detected area.

🚗 No Immediate Fire Detection

The robot uses the flame sensor readings to determine its direction:

- Fire toward the right → move/turn right
- Fire toward the front → move forward
- Fire toward the left → move/turn left
- No relevant detection → stop

🚧 Obstacle Detection

The HC-SR04 ultrasonic sensor continuously measures the distance in front of the robot.

If an obstacle is detected within 15 cm:

1. The pump is switched off.
2. The buzzer turns on.
3. The robot stops.
4. The robot moves backward.
5. The robot turns right.
6. The robot continues its operation.

🔄 Servo Mechanism

The servo motor controls the direction of the water nozzle.

The nozzle sweeps through different angles so that water can cover a wider area instead of spraying in only one direction.

💻 Software

The project is programmed using:

- Arduino IDE
- Arduino C/C++

📂 Files

Fire_Fighting_Robot/
│
├── Fire_Fighting_Robot.ino
└── README.md

🚀 How to Use

1. Connect all components according to the pin configuration.
2. Open "Fire_Fighting_Robot.ino" in Arduino IDE.
3. Select the appropriate Arduino board.
4. Select the correct COM port.
5. Upload the program.
6. Place the robot in an open test area.
7. Provide a safe flame-detection test environment.
8. Observe the robot's autonomous movement and fire-extinguishing response.

⚠️ Safety

This project involves a water pump, motors, batteries, and fire detection.

- Test the robot in a controlled environment.
- Keep electronics protected from water.
- Use an appropriate power supply.
- Do not test with uncontrolled or large flames.
- Keep a suitable fire-safety method available during testing.
- Supervise the robot during operation.

🎯 Features

- Autonomous fire detection
- Direction-based movement
- Automatic water spraying
- Servo-controlled nozzle
- Ultrasonic obstacle avoidance
- Audible alerts
- Two-motor differential drive

🔮 Future Improvements

Possible improvements include:

- Adding more accurate flame detection
- Using multiple ultrasonic sensors for better navigation
- Adding a temperature sensor
- Adding a camera for visual fire detection
- Using IoT for remote monitoring
- Adding automatic water-level monitoring
- Improving obstacle-avoidance algorithms
- Adding rechargeable battery monitoring

👩‍💻 Project

Project: Arduino Fire-Fighting Robot
Platform: Arduino
Application: Autonomous Fire Detection and Extinguishing
