//作品名稱:讀卡機

//匯入函式庫
#include <SPI.h>
#include <MFRC522.h>
#define RESET 9//重置腳位
#define SS 10//晶片選擇腳位
MFRC522 rc522(SS, RESET);//初始化物件
void setup() {//初始化序列埠 SPI介面 物件
Serial.begin(9600);
SPI.begin();
rc522.PCD_Init();
}
void loop() {
if(rc522.PICC_IsNewCardPresent()){//判斷感應新卡片
  if(rc522.PICC_ReadCardSerial()){
    byte *id=rc522.uid.uidByte;//讀取卡片ID
    int len=rc522.uid.size;//ID長度
    for(int i=0;i<len;i++){
      Serial.print("0x");
      Serial.print(id[i], HEX);//16進位顯示ID到監控視窗
      Serial.print(" ");
    }
    Serial.println();
  }
  rc522.PICC_HaltA();//避免重複讀取
}
}
