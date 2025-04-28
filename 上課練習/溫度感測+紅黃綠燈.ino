//溫度感測 低於30亮黃LED 31-35亮綠LED 36亮紅LED
//導入函式庫，定義接腳
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPin 2
#define DHTType DHT11
//第4腳黃燈 第5腳綠燈 第6腳紅燈
const byte y = 4;
const byte g = 5;
const byte r = 6;
//初始化dht11
DHT dht11(DHTPin,DHTType);
//初始化LCD
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
Serial.begin(9600);
lcd.init();//初始化LCD
lcd.begin(16,2);
lcd.backlight();//啟用背光
dht11.begin();
for(int i=4;i<6;i++){
  pinMode(i, OUTPUT);
  digitalWrite(i, LOW);
}
}

void loop() {
//宣告h及t的資料型態 將讀取到的溫溼度放入變數
float t = dht11.readTemperature();
if (isnan(t)){//若h或t不是數值 印出error 並不再次執行
  Serial.println("error");
  return;
}
else{
//顯示到溫度到LCD
    lcd.setCursor(0,0);
    lcd.print(t);
    lcd.print("C ");
// 顯示溫度到監控視窗
    Serial.print(" ");
    Serial.print(t);
    Serial.println("C");
    if(t<30){
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
    else if(t>31 and t<36){
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(6,LOW);
    }
    else if(t>36){
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
    }
  }
delay(2000);
}
