#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPin 2
#define DHTType DHT11
DHT dht11(DHTPin,DHTType);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
void setup() {
Serial.begin(9600);
lcd.init();
lcd.begin(16,2);
lcd.backlight();
dht11.begin();
}

void loop() {
float h = dht11.readHumidity();
float t = dht11.readTemperature();
if (isnan(h) || isnan(t)){
  Serial.println("error");
  return;
}
else{
  lcd.setCursor(0, 0);
  lcd.print(t);
  lcd.print("C ");
  lcd.print(h);
  lcd.print("%");
}
delay(2000);
}
