#include <SPI.h>
#include "RF24.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //1602LCD  SDA->A4  SCL->A5
RF24 rf24(7,8);
const byte addr[] = "CHEN";//nrf24通訊密碼
String msg;
int f0 ;//A0fort0砲台
int f1 ;//A1fort1
int f2 ;//A2fort2
int f3 ;//A3fort3
int ru ;//A6rudder
int en ;//A7engine
int s=0;
//LED
int L0=4;
int L1=5;
//button
int BU1=2;
int BU2=3;
int BU3=6;
int BU4=9;
//button變數
int B1R=0;
int B2R=0;
int B3R=0;
int B4R=0;
int BS1;
int BS2;
int BS3;
int BS4;
void setup() {
  Serial.begin(9600);
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(BU1, INPUT);
  pinMode(BU2, INPUT);
  pinMode(BU3, INPUT);
  pinMode(BU4, INPUT);
  
  digitalWrite(L0, HIGH);  
  rf24.begin();
  rf24.setChannel(83);       // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);   // 設定廣播功率
  rf24.setDataRate(RF24_2MBPS); // 設定傳輸速率
  rf24.openWritingPipe(addr); // 設定通道位址
  rf24.stopListening();       // 停止偵聽；設定成發射模式
  //LCD
  lcd.begin(16,2);//設定螢幕長寬
  lcd.backlight();//開啟背光
    delay(250);    
  lcd.noBacklight();//關掉背光
      delay(250);
  lcd.backlight(); //開啟背光
    delay(250);
}
void loop() {
  button();
  f0=analogRead(A0)/5.6;
  f1=analogRead(A1)/5.6;
  f2=analogRead(A2)/5.6;
  f3=analogRead(A3)/5.6;
  ru=analogRead(A6)/5.6;
  en=analogRead(A7)/2;
  Serial.print("fort=");
  Serial.println(f0);
  Serial.print("fort1=");
  Serial.println(f1);
  Serial.print("fort2=");
  Serial.println(f2);
  Serial.print("fort3=");
  Serial.println(f3);
  Serial.print("rudder=");
  Serial.println(ru);
  Serial.print("engine=");
  Serial.println(en);
  wrong();
  if(s==1){
  msg=String(f0)+";"+String(f1)+";"+String(f2)+";"+String(f3)+";"+String(ru)+";"+String(en)+";"+String(BS1)+";"+String(BS2)+";"+String(BS3)+";"+String(BS4)+";";
  rf24.write(&msg[0],40);  // 傳送資料
  Serial.print("msg=");
  Serial.println(msg);
  digitalWrite(L1, HIGH); 
  LCD1602();
  digitalWrite(L1, LOW); 
  }
}
