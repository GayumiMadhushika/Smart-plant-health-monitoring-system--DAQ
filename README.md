# Smart-plant-health-monitoring-system--DAQ

## 📌 Project Overview
This project aims to **enhance plant health monitoring** through **real-time data acquisition and visualization**. By integrating **sensors, an Arduino Uno, and LabVIEW**, this system helps monitor key environmental factors crucial for plant growth.

## 💡 Highlights
- **Real-time data visualization** using **LabVIEW** with intuitive graphs for:
  - 🌿 Soil Moisture Levels
  - ☀️ Light Intensity
  - ⚗️ Soil pH Levels
- **Threshold-based LED Indication:**
  - **Red LED** 🔴 - Indicates **high** sensor readings beyond the threshold.
  - **Green LED** 🟢 - Indicates **low** sensor readings below the threshold.
  - **No LED** - Sensor values are within the optimal range.
- **User-friendly interface** for quick plant condition analysis.

## 🌍 Impact
This project demonstrates how **technology supports agriculture and plant care**, providing **actionable insights** to maintain **optimal growing conditions** for plants like **Aloe Vera**. The system is adaptable for **smart farming, greenhouse monitoring, and automated irrigation systems**.

## 🛠 Tools & Technologies Used
### **Hardware:**
- Arduino Uno
- **Sensors:**
  - 🌱 **Soil Moisture Sensor** (Resistive)
  - ☀️ **TEMT6000 Light Sensor**
  - ⚗️ **Potentiometer (as Soil pH Sensor)**
- **6 LEDs** (Threshold Indicators)
- Circuit wires, breadboard, resistors

### **Software:**
- LabVIEW (for real-time data visualization)
- Arduino IDE (for programming and serial communication)

## 🏗 System Workflow
1. **Data Collection:** Sensors measure soil moisture, light intensity, and soil pH.
2. **Data Transmission:** Arduino Uno transmits sensor values via **serial communication (USB/UART)**.
3. **Data Processing & Visualization:** LabVIEW processes the data and updates real-time **graphs**.
4. **Threshold Indication:** LED indicators light up based on predefined **Aloe Vera plant health ranges**.

## 📊 Threshold Values for Aloe Vera
| Parameter         | Low Threshold | Optimal Range | High Threshold |
|------------------|--------------|--------------|--------------|
| **Soil Moisture** | Below 10V     | 10V - 35V     | Above 35V     |
| **Soil pH**       | Below 5.5     | 5.5 - 7.5     | Above 7.5     |
| **Light Intensity** | Below 10V     | 10V - 15V     | Above 15V     |

## 🚀 Getting Started
### **Hardware Setup:**
1. Connect **Soil Moisture Sensor** to **A0**.
2. Connect **Light Sensor** to **A1**.
3. Connect **Potentiometer (pH Sensor)** to **A2**.
4. Connect **LED indicators** to **digital pins (D1-D6)**.
5. Power the circuit using **Arduino Uno via USB**.


