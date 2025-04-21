#include <SPI.h> // include函式
byte Decode = 0x9; //編碼模式
byte Intensity = 0xA; //LED亮度
byte Scan = 0xB; //資料暫存器個數
byte Shutdown = 0xC; //開關MAX7219
byte Test = 0xF; //TEST模式
void max7219(byte r,byte d){
  digitalWrite(SS, LOW);
  SPI.transfer(r);
  SPI.transfer(d);
  digitalWrite(SS, HIGH);
}
//自訂義函式
void clear(){
  for (int i=1;i<=8;i++){
    max7219(i, 0);//關閉所有LED
  }
}
byte data[2][8]={{0x00,0x18,0x18,0x3C,0x3A,0x18,0x28,0x00},//儲存傳到暫存器的資料
                {0x00,0x18,0x18,0x3C,0x5C,0x18,0x14,0x00}};
void setup() {
SPI.begin(); //啟用SPI
max7219(Decode,0); //使用資料模式
max7219(Intensity,7); //LED亮度為7
max7219(Scan,7); //啟用資料暫存器
max7219(Shutdown,1); //啟用MAX7219
max7219(Test,0); //不進入測試模式
clear(); //設定所有暫存器為0
}
 
void loop() {
//將陣列data[]以及tmp[]寫入資料暫存器
for(int i=0;i<2;i++){
  for(int j=0;j<8;j++){
    max7219(j+1, data[i][j]); //將陣列data[][]寫入資料暫存器
  } 
  delay(300); //圖形移動快慢
}
 
}
