//8*8LED 指定某行某列 只有指定的區域亮燈
//此範例指定第六列 第五行亮燈

void setup() {
  //設定接腳
  for (int i = 2; i <= 13; i++) {  //1-12隻腳
    pinMode(i, OUTPUT);
  }

  //13-16腳
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  //列為L 行為C
  //L低態(LOW)不亮 C高態(HIGH)不亮
  digitalWrite(2, LOW);   //第一列
  digitalWrite(3, LOW);   //第二列
  digitalWrite(4, LOW);   //第三列
  digitalWrite(5, LOW);   //第四列
  digitalWrite(6, LOW);   //第五列
  digitalWrite(7, HIGH);  //第六列
  digitalWrite(8, LOW);   //第七列
  digitalWrite(9, LOW);   //第八列

  digitalWrite(10, HIGH); //第一行
  digitalWrite(11, HIGH); //第二行
  digitalWrite(12, HIGH); //第三行
  digitalWrite(13, HIGH); //第四行
  digitalWrite(A0, LOW);  //第五行
  digitalWrite(A1, HIGH); //第六行
  digitalWrite(A2, HIGH); //第七行
  digitalWrite(A3, HIGH); //第八行
}
