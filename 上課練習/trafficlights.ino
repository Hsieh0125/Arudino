#未完成待修改

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

void showFigure(byte fig[8]) {
  for (int i = 0; i < 8; i++) {
    max7219(i + 1, fig[i]);
  }
}

//儲存傳到暫存器的資料
byte data[2][8]={{0x00,0x18,0x18,0x3C,0x3A,0x18,0x28,0x00},//綠燈
                {0x00,0x18,0x18,0x3C,0x5C,0x18,0x14,0x00}};
                
byte data_red[8]={0x00,0x18,0x18,0x3C,0x3C,0x18,0x18,0x00};//紅燈

void setup() {
SPI.begin(); //啟用SPI
max7219(Decode,0); //使用資料模式
max7219(Intensity,7); //LED亮度為7
max7219(Scan,7); //啟用資料暫存器
max7219(Shutdown,1); //啟用MAX7219
max7219(Test,0); //不進入測試模式
clear(); //設定所有暫存器為0
 
for(int i=2;i<=4;i++){
  pinMode(i, OUTPUT);
}
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
}
void loop() {
//將陣列data[]以及tmp[]寫入資料暫存器
  
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  showFigure(data_red);
  delay(3000);

  
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  clear();
  delay(1000);
  digitalWrite(4, LOW);

  
  digitalWrite(3, HIGH);
  for (int t = 0; t < 10; t++) {
    showFigure(data[0]);
    if (t < 6) {
      delay(300); 
    } else {
      delay(150); 
    }

    showFigure(data[1]);
    if (t < 6) {
      delay(300);
    } else {
      delay(150);
    }
  }
  digitalWrite(3, LOW);

 
  digitalWrite(4, HIGH);
  clear();
  delay(1000);
  digitalWrite(4, LOW);
}

 

