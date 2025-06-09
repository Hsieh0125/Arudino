//題目:超音波距離感測器
//設定接腳
const byte trigpin=4;
const byte echopin=5;
void setup() {
//設定接腳輸入/出模式
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
}
void loop() {
float dur,dis;//宣告浮點變數
digitalWrite(trigpin,HIGH);
delayMicroseconds(1000);//delay1000微秒
digitalWrite(trigpin,LOW);
dur=pulseIn(echopin,HIGH);//測量trigpin收到電壓訊號的時間
dis=dur/58.8;//獲得距離
Serial.print(dis);//顯示至監控視窗
Serial.println("cm");
delay(1000);
}
