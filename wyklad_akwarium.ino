#include <OneWire.h>
#include <DS18B20.h>
#include <LiquidCrystal_I2C.h>
#define ONEWIRE_PIN 2
LiquidCrystal_I2C lcd(0x27,20,4);
byte address_1[8] = {0x28, 0xD4, 0x83, 0x79, 0x97, 0x8, 0x3, 0x7E};
byte address_2[8] = {0x28, 0xD4, 0x83, 0x79, 0x97, 0x8, 0x3, 0x7E};
byte address_3[8] = {0x28, 0xD4, 0x83, 0x79, 0x97, 0x8, 0x3, 0x7E};
OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);
void setup() {
  while(!Serial);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  sensors.begin();
  sensors.request(address_1);
  sensors.request(address_2);
  sensors.request(address_3);
}

void loop() {
  if (sensors.available())
  {
    t1();
    t2();
    t3();
  } 
}
void t1(){
    float temperature = sensors.readTemperature(address_1);
    lcd.clear();
    Serial.print(temperature);
    Serial.println(F(" 'C"));
    lcd.setCursor(0,0);
    lcd.print("temperatura 1");    
    lcd.setCursor(0,1);
    temperature = 
    lcd.print(temperature);
    lcd.setCursor(5,1);
    lcd.print("'C");
    sensors.request(address_1);
    delay(2000);
}
void t2(){
    float temperature = sensors.readTemperature(address_2);
    lcd.clear();
    Serial.print(temperature);
    Serial.println(F(" 'C"));
    lcd.setCursor(0,0);
    lcd.print("temperatura 2");    
    lcd.setCursor(0,1);
    temperature = 
    lcd.print(temperature);
    lcd.setCursor(5,1);
    lcd.print("'C");
    sensors.request(address_2);
    delay(2000);
}
void t3(){
    float temperature = sensors.readTemperature(address_3);
    lcd.clear();
    Serial.print(temperature);
    Serial.println(F(" 'C"));
    lcd.setCursor(0,0);
    lcd.print("temperatura 3");    
    lcd.setCursor(0,1);
    temperature = 
    lcd.print(temperature);
    lcd.setCursor(5,1);
    lcd.print("'C");
    sensors.request(address_3);
    delay(2000);
}
