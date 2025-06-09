#include <DHT.h>
#define DHTPin 2
#define DHTType DHT11
DHT dht11(DHTPin,DHTType);
const byte trigpin=4;
const byte echopin=5;
const int buzpin=9;
void setup(){
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(buzpin,OUTPUT);
lcd.begin(16,2);
lcd.backlight();
dht11.begin();
}
void loop(){
float dur,dis;//宣告浮點變數
digitalWrite(trigpin,HIGH);
delayMicroseconds(1000);//delay1000微秒
digitalWrite(trigpin,LOW);
dur=pulseIn(echopin,HIGH);//測量trigpin收到電壓訊號的時間
dis=dur/58.8;//獲得距離
Serial.print(dis);//顯示至監控視窗
Serial.println("cm");
lcd.setCursor(0,0);

if(dis<=5){
 tone(buzpin,950);  
}

delay(1000);
}
