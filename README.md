                    **Autonomous Baby Incubator**

This repository contains the design, implementation, and documentation for an **Arduino-based autonomous baby incubator**. It is a low-cost solution aimed at maintaining optimal temperature and humidity levels for preterm or sick infants.

### **Overview**
Preterm births account for up to 20% of all births globally, with millions of infants requiring specialized care annually. This project tackles the challenge by providing a controlled environment to improve survival rates. The incubator is capable of:
- Monitoring temperature and humidity using sensors.
- Automatically adjusting environmental conditions through actuators.
- Displaying real-time data on an LCD.

---

### **Features**
- **Temperature Control**: Uses coil heaters controlled by relays for precise heating.
- **Humidity Control**: Includes an ultrasonic mist maker for maintaining required humidity levels.
- **Air Circulation**: A fan ensures uniform air distribution for temperature and humidity.
- **User Interface**: Dot-matrix LCD displays real-time data and allows input for required conditions.

---

### **Components**
1. **Arduino Mega 2560**: The brain of the incubator, responsible for processing data and controlling actuators.
2. **DHT11 Sensor**: Measures temperature and humidity within the chamber.
3. **Heating Coils**: Provides the required warmth inside the incubator.
4. **Ultrasonic Mist Maker**: Generates fine water droplets for humidity.
5. **12V DC Fan**: Circulates air for even heat and humidity distribution.
6. **L298N H-Bridge**: Drives the motorized fan and other actuators.
7. **5V Relay Module**: Switches the heating coils based on Arduino signals.
8. **Dot-Matrix LCD**: Displays temperature, humidity, and system status.
9. **Power Supply**: Converts 220V AC to the required 5V and 12V DC.

---

### **Circuit Diagram**
The full schematic includes:
- Arduino Mega 2560
- DHT11 Sensor
- Heating coils connected via relays
- Ultrasonic mist maker
- Dot-matrix LCD
- 12V DC fan
- Power supply

The circuit diagram is provided in the repository.

---

### **Working Principle**
The incubator works by comparing the current and required values of temperature and humidity:
- **Error Correction**: The Arduino calculates the error (`required value - current value`) and adjusts the actuators accordingly.
- **Heating**: If the temperature is lower than required, the heating coils are activated.
- **Cooling**: If the temperature exceeds the threshold, the fan is activated.
- **Humidification**: The ultrasonic mist maker generates moisture, and the fan distributes it evenly.
- **Dehumidification**: The fan increases speed to reduce humidity if it exceeds the required level.

---

### **Applications**
- Providing a controlled environment for preterm infants.
- Preserving sensitive chemical reagents.
- Controlled environments for medicines and edibles.
- Applications in egg hatching.

---

### **Future Work**
- Adding an oxygen source with flowrate control.
- Incorporating multiple body temperature sensors for better accuracy.
- Enhancing the versatility of the control unit.

---

### **How to Use**
1. **Hardware Setup**:
   - Assemble the components as per the circuit diagram.
   - Connect sensors, actuators, and power supply to the Arduino Mega 2560.
2. **Upload Code**:
   - Upload the Arduino code provided in the `Arduino_Code` folder to the microcontroller.
3. **Operating the Incubator**:
   - Power the incubator using a 220V AC supply.
   - Use the pushbuttons to set the desired temperature and humidity levels.
   - Monitor the real-time conditions on the LCD display.

---

### **Cost Details**
| Component                | Model                        | Price (PKR) |
|--------------------------|------------------------------|-------------|
| Acryl Casing             | 18x18x12 inches             | 2300        |
| Arduino Mega 2560        | -                            | 1150        |
| H-Bridge                 | L298N                       | 150         |
| Power Supply             | 220V AC to 24V DC           | 400         |
| DHT11 Sensor             | -                            | 80 x 2      |
| Pushbuttons              | -                            | 30 x 6      |
| Relay                    | 5V DC Control               | 40          |
| LCD                      | Dot Matrix                  | 250         |
| Fan                      | 12V DC                      | 200         |
| Heater                   | Coiled Heating Element      | 70 x 2      |
| Ultrasonic Mist Maker    | 24V DC                      | 1000        |
| Travel                   | Economic Class              | 400         |
| Silicon Glue & Tape      | -                            | 160         |
| **Total**                |                              | **6450**    |

---

### **Repository Contents**
- **`/Arduino_Code`**: Includes the Arduino `.ino` file for running the incubator.
- **`/Circuit_Diagram`**: Schematic of the incubator's control system.
- **`/Documentation`**: Project report detailing the design, working, and applications.

---

Let me know if you need additional edits or sections added!
