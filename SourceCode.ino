#include "Megatronics_pk_lcd.h" // Import LCD library
#include "DHT.h"

// DHT Sensor Configuration
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LCD Configuration
Megatronics_pk_lcd lcd(8, 9, 11, 10); // RST, MISO, MOSI, SCK

// Pin Definitions
const int fan = 4;
const int IN1 = 24;
const int IN2 = 25;
const int heater = 5;
const int fogger = 22;

// Variables
float temperaturein;
float humidityin;
float errortemperature;
float errorhumidity;
const int speed = 150; // Fan speed
const float reqtemperature = 34.0; // Required temperature in °C
const float reqhumidity = 45.0; // Required humidity in %

void setup() {
  // Initialize LCD and DHT
  lcd.Begin();
  lcd.Clear_LCD();
  dht.begin();

  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  // Configure Pins
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(fogger, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Read DHT Sensor Data
  humidityin = dht.readHumidity();
  temperaturein = dht.readTemperature();

  // Display Data on Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidityin);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperaturein);
  Serial.println(" *C");

  // Calculate Errors
  errortemperature = temperaturein - reqtemperature;
  errorhumidity = humidityin - reqhumidity;

  // Update LCD
  lcd.print(1, 5, 1, "TEMPERATURE=");
  lcd.print(70, 5, 2, temperaturein);
  lcd.print(85, 5, 1, "C");
  lcd.print(1, 15, 1, "HUMIDITY=");
  lcd.print(55, 15, 2, humidityin);
  lcd.print(70, 15, 1, "%");
  lcd.print(1, 30, 1, "-------------------------------------------");
  lcd.print(1, 40, 1, "REQUIREDT=");
  lcd.print(70, 40, 2, reqtemperature);
  lcd.print(85, 40, 1, "C");
  lcd.print(1, 50, 1, "REQUIREDH=");
  lcd.print(60, 50, 2, reqhumidity);
  lcd.print(75, 50, 1, "%");
  lcd.Update();
  delay(50); // Short delay for LCD update
  lcd.Clear_LCD();

  // Fan Speed Control
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(fan, speed);

  // Temperature and Humidity Control Logic
  if (errortemperature > 0) {
    digitalWrite(fan, HIGH);  // Decrease temperature
    digitalWrite(heater, LOW);
  } else if (errortemperature < 0) {
    digitalWrite(heater, HIGH); // Increase temperature
    digitalWrite(fan, HIGH);
  }

  if (errorhumidity > 0) {
    digitalWrite(fan, HIGH); // Decrease humidity
    digitalWrite(fogger, LOW);
  } else if (errorhumidity < 0) {
    digitalWrite(fogger, HIGH); // Increase humidity
    digitalWrite(fan, HIGH);
  }

  // Stop Fan and Heater when Errors are Zero
  if (errortemperature == 0) {
    digitalWrite(heater, LOW);
    digitalWrite(fan, LOW);
  }
  if (errorhumidity == 0) {
    digitalWrite(fogger, LOW);
    digitalWrite(fan, LOW);
  }

  delay(1000); // Delay for next loop
}
