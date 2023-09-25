#include <SPI.h>
#include "RF24.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//NANO 1602LCD  SDA->A4  SCL->A5  MEGA2560 1602LCD  SDA->20  SCL->21
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
//RF24 rf24(7,8);//NANO
RF24 rf24(49,48);//mega2560
const byte addr[] = "CHEN";//nrf24通訊密碼
String msg;
//砲台
int f1 ;//fort1
int f2 ;//fort2
int f3 ;//fort3
int ru ;//rudder舵片
int en ;//engine引擎
int s=0;//安全鎖
//LED
int L0=9;
int L1=11;
//button
int BU1=1;
int BU2=3;
int BU3=5;
int BU4=7;
//button變數
int B1R=0;
int B2R=0;
int B3R=0;
int B4R=0;
int BS1;
int BS2;
int BS3;
int BS4;
//切換
int c=0;
void setup() {
  Serial.begin(9600);
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(BU1, INPUT);
  pinMode(BU2, INPUT);
  pinMode(BU3, INPUT);
  pinMode(BU4, INPUT);
  //digitalWrite(L0, HIGH);  
  rf24.begin();
  rf24.setChannel(83);       // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);   // 設定廣播功率
  rf24.setDataRate(RF24_2MBPS); // 設定傳輸速率
  rf24.openWritingPipe(addr); // 設定通道位址
  rf24.stopListening();       // 停止偵聽；設定成發射模式
  //LCD
  lcd.begin(16,2);//設定螢幕長寬   
  lcd.noBacklight();//關掉背光
      delay(250);
  lcd.backlight(); //開啟背光
    delay(250);
}
void loop() {
  button();
  en=analogRead(A0)/2;
  ru=analogRead(A2)/5.6;
  f1=analogRead(A4)/3.79;
  f2=analogRead(A6)/3.79;
  f3=analogRead(A8)/3.79;
  Serial.print("engine=");
  Serial.println(en);
  Serial.print("rudder=");
  Serial.println(ru);
  Serial.print("fort1=");
  Serial.println(f1);
  Serial.print("fort2=");
  Serial.println(f2);
  Serial.print("fort3=");
  Serial.println(f3);
  wrong();
  // 傳送資料
  if(s==1){
    if(c==0){
  msg=String(c)+";"+String(en)+";"+String(ru)+";"+String(f1)+";"+String(f2)+";"+String(f3)+";"+String(BS1)+";"+String(BS2)+";"+String(BS3)+";"+String(BS4)+";";
  rf24.write(&msg[0],40);  
  c=1;
  Serial.print("msg=");
  Serial.println(msg);
    }else if(c==1){
  msg=String(c)+";"+String(123)+";"+String(456)+";"+String(77)+";"+String(f2)+";"+String(f3)+";"+String(BS1)+";"+String(BS2)+";"+String(BS3)+";"+String(85)+";";
  rf24.write(&msg[0],40);
  c=0;
  Serial.print("msg=");
  Serial.println(msg);
      }
  
  //digitalWrite(L1, HIGH); 
  LCD1602();
  //digitalWrite(L1, LOW); 
  }
}
