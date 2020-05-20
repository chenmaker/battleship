#include <SPI.h>
#include "RF24.h"

RF24 rf24(7,8);
const byte addr[] = "CHEN";
String msg;
int f0 ;//A0fort0
int f1 ;//A1fort1
int f2 ;//A2fort2
int f3 ;//A3fort3
int f4 ;//A4fort4
int f5 ;//A5fort5
int ru ;//A6rudder
int en ;//A7engine
int L0=6;
int L1=5;
int L2=4;
int L3=3;
void setup() {
  Serial.begin(9600);
 // pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
 // pinMode(L2, OUTPUT);
 // pinMode(L3, OUTPUT);
 // digitalWrite(L0, LOW); 
  digitalWrite(L1, LOW); 
  //digitalWrite(L2, LOW); 
  //digitalWrite(L3, LOW); 
//pinMode(D1, INPUT);//開關
  rf24.begin();
  rf24.setChannel(83);       // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);   // 設定廣播功率
  rf24.setDataRate(RF24_2MBPS); // 設定傳輸速率
  rf24.openWritingPipe(addr); // 設定通道位址
  rf24.stopListening();       // 停止偵聽；設定成發射模式
}
void loop() {
  f0=analogRead(A0)/5.6;
  f1=analogRead(A1)/5.6;
  f2=analogRead(A2)/5.6;
  f3=analogRead(A3)/5.6;
 // f4=analogRead(A4)/5.6;
 // f5=analogRead(A5)/5.6;
  ru=analogRead(A4)/5.6;
  en=analogRead(A5)/4;
  Serial.print("fort=");
  Serial.println(f0);
  Serial.print("fort1=");
  Serial.println(f1);
  Serial.print("fort2=");
  Serial.println(f2);
  Serial.print("fort3=");
  Serial.println(f3);
  Serial.print("fort4=");
  Serial.println(f4);
  Serial.print("fort5=");
  Serial.println(f5);
  Serial.print("rudder=");
  Serial.println(ru);
  Serial.print("engine=");
  Serial.println(en);
  //msg=String(f0)+";"+String(f1)+";"+String(f2)+";"+String(f3)+";"+String(f4)+";"+String(f5)+";"+String(ru)+";"+String(en)+";";
  msg=String(f0)+";"+String(f1)+";"+String(f2)+";"+String(f3)+";"+String(ru)+";"+String(en)+";";
  rf24.write(&msg[0],40);  // 傳送資料
  Serial.print("msg=");
  Serial.println(msg);
  //digitalWrite(L0, HIGH); 
  digitalWrite(L1, HIGH); 
  //digitalWrite(L2, HIGH); 
  //digitalWrite(L3, HIGH); 
  delay(500);
  //digitalWrite(L0, LOW); 
  digitalWrite(L1, LOW); 
  //digitalWrite(L2, LOW); 
  //digitalWrite(L3, LOW);
}
