#include <SPI.h>
#include "RF24.h"
#include <SparkFun_TB6612.h>
#include <Servo.h>
Servo sf0;
Servo sf1;
Servo sf2;
Servo sf3;
Servo sf4;
Servo sf5;
Servo sru;
RF24 rf24(49,48);
const byte addr[] = "CHEN";
const byte pipe = 1;  // 指定通道編號
int commaPosition;
String message;
int any[40];
int e;
int L0=6;
//TB6612
#define AIN1 5  // 控制輸入A1
#define AIN2 6   // 控制輸入A2
#define BIN1 4   // 控制輸入B1
#define BIN2 3   // 控制輸入B2
#define PWMA 7
#define PWMB 2
#define STBY 25  // 「待機」控制接Arduino的11腳

const int offsetA = 1;  // 正反轉設定A，可能值為1或-1。
const int offsetB = 1;  // 正反轉設定B，可能值為1或-1。

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int f0 ;//A0fort0
int f1 ;//A1fort1
int f2 ;//A2fort2
int f3 ;//A3fort3
//int f4 ;//A4fort4
//int f5 ;//A5fort5
int ru ;//A6rudder
int en ;//A7engine

char data[10];
int index,panAngle,tiltAngle;
char *p;
void setup() {
  //PWM 8 9 10 11 12 13 44 45 46
  sf0.attach(13);
  sf1.attach(12);
  sf2.attach(11);
  sf3.attach(10);
  sf4.attach(9);
  sf5.attach(8);
  sru.attach(45);
  pinMode(L0,OUTPUT);
  Serial.begin(9600);
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);
  rf24.setDataRate(RF24_2MBPS);
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
  Serial.println("nRF24L01 ready!");
}

void loop() {   
  if (rf24.available(&pipe)) {
    char msg[40]="";
    rf24.read(&msg, sizeof(msg));
    Serial.println(msg); // 顯示訊息內容 
    for(int i=0;i<=40;i++){
      message+=msg[i];
      //Serial.println(message); 
      digitalWrite(L0, HIGH);
      }
   }
   mg();
   en=any[5];
   motor1.drive(en);       
   motor2.drive(en);   
   sru.write(any[4]);
   sf0.write(any[0]);
   sf1.write(any[1]);
   sf2.write(any[2]);
   sf3.write(any[3]);
  //sf4.write(any[4]);
  //sf5.write(any[5]);
  digitalWrite(L0, LOW);
}
