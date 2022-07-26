#include <DHT.h>
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>

#define DHT_TYPE DHT11

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT_Unified dht(13, DHT_TYPE);
sensor_t sensor;

void setup() {
  Serial.begin(9600);
  dht.begin();
  dht.temperature().getSensor(&sensor);
  lcd.begin(16, 2);
  lcd.print("Current Temp:");
}

void loop() {
  delay(sensor.min_delay / 1000);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
    lcd.setCursor(0, 1);
    lcd.print(event.temperature * 9 / 5 + 32);
    lcd.print("F");
  }
}
