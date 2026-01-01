/*
  temperature_sensor.ino
  Read TMP36 on A0 and display on 16x2 LCD + Serial Monitor.
  Configured for Tinkercad (TMP36).

  Wiring (TMP36):
    left -> 5V
    middle -> Vout -> A0
    right -> GND

  LCD (4-bit mode):
    RS -> D12
    E  -> D11
    D4 -> D5
    D5 -> D4
    D6 -> D3
    D7 -> D2
    RW -> GND
    VSS -> GND
    VCC -> 5V
    VO -> Pot middle (10k pot ends -> 5V & GND)
*/

#include <LiquidCrystal.h>

#define SENSOR_PIN A0
#define SENSOR_TYPE_LM35 1
#define SENSOR_TYPE_TMP36 2
#define SENSOR_TYPE SENSOR_TYPE_TMP36  // TMP36 in Tinkercad

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int samples = 10;
const unsigned long delayMs = 1000;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Temp sensor demo");
  delay(1000);
}

float readTemperatureC() {
  long total = 0;
  for (int i = 0; i < samples; ++i) {
    total += analogRead(SENSOR_PIN);
    delay(5);
  }
  float avg = total / (float)samples;
  const float vRef = 5.0;
  float voltage = (avg * vRef) / 1023.0;

#if SENSOR_TYPE == SENSOR_TYPE_LM35
  return voltage * 100.0;
#elif SENSOR_TYPE == SENSOR_TYPE_TMP36
  float v_mV = voltage * 1000.0;
  return (v_mV - 500.0) / 10.0;
#else
  return 0.0;
#endif
}

void loop() {
  float tempC = readTemperatureC();
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  Serial.print("Temperature: ");
  Serial.print(tempC, 2);
  Serial.print(" C\t");
  Serial.print(tempF, 2);
  Serial.println(" F");

  lcd.setCursor(0, 0);
  lcd.print("Temp:            ");
  lcd.setCursor(6, 0);
  lcd.print(tempC, 2);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Serial:");
  lcd.setCursor(7, 1);
  lcd.print("ON ");

  delay(delayMs);
}
/*
  temperature_sensor.ino
  Read TMP36 on A0 and display on 16x2 LCD + Serial Monitor.
  Configured for Tinkercad (TMP36).

  Wiring (TMP36):
    left -> 5V
    middle -> Vout -> A0
    right -> GND

  LCD (4-bit mode):
    RS -> D12
    E  -> D11
    D4 -> D5
    D5 -> D4
    D6 -> D3
    D7 -> D2
    RW -> GND
    VSS -> GND
    VCC -> 5V
    VO -> Pot middle (10k pot ends -> 5V & GND)
*/

#include <LiquidCrystal.h>

#define SENSOR_PIN A0
#define SENSOR_TYPE_LM35 1
#define SENSOR_TYPE_TMP36 2
#define SENSOR_TYPE SENSOR_TYPE_TMP36  // TMP36 in Tinkercad

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int samples = 10;
const unsigned long delayMs = 1000;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Temp sensor demo");
  delay(1000);
}

float readTemperatureC() {
  long total = 0;
  for (int i = 0; i < samples; ++i) {
    total += analogRead(SENSOR_PIN);
    delay(5);
  }
  float avg = total / (float)samples;
  const float vRef = 5.0;
  float voltage = (avg * vRef) / 1023.0;

#if SENSOR_TYPE == SENSOR_TYPE_LM35
  return voltage * 100.0;
#elif SENSOR_TYPE == SENSOR_TYPE_TMP36
  float v_mV = voltage * 1000.0;
  return (v_mV - 500.0) / 10.0;
#else
  return 0.0;
#endif
}

void loop() {
  float tempC = readTemperatureC();
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  Serial.print("Temperature: ");
  Serial.print(tempC, 2);
  Serial.print(" C\t");
  Serial.print(tempF, 2);
  Serial.println(" F");

  lcd.setCursor(0, 0);
  lcd.print("Temp:            ");
  lcd.setCursor(6, 0);
  lcd.print(tempC, 2);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Serial:");
  lcd.setCursor(7, 1);
  lcd.print("ON ");

  delay(delayMs);
}
