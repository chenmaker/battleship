#include <SPI.h>
#include "RF24.h"//nrf24
#include <SparkFun_TB6612.h>//馬達控制
#include <Thermistor.h>//溫度
#include <Servo.h>//伺服馬達
Servo sf0;
Servo sf1;
Servo sf2;
Servo sf3;
Servo sf4;
Servo sru;
//溫度
Thermistor temp(0);
Thermistor temp1(1);
int temperature = temp.getTemp();
int temperature1 = temp1.getTemp();
//nrf24
RF24 rf24(49,48);
const byte addr[] = "CHEN";
const byte pipe = 1;  // 指定通道編號
int commaPosition;
String message;
int any[40];
int e;
int L0=46,L1=44,L2=47,L3=45,L4=43,L5=23,L6=25,L7=27;//LED
//TB6612
#define AIN1 5   // 控制輸入A1
#define AIN2 6   // 控制輸入A2
#define BIN1 4   // 控制輸入B1
#define BIN2 3   // 控制輸入B2
#define PWMA 7   // 控制速度
#define PWMB 2   // 控制速度
#define STBY 53   // 控制待機 
const int offsetA = 1;  // 正反轉設定A，可能值為1或-1。
const int offsetB = 1;  // 正反轉設定B，可能值為1或-1。
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
//控制板腳位
int f0 ;//A0fort0
int f1 ;//A1fort1
int f2 ;//A2fort2
int f3 ;//A3fort3
int ru ;//A6rudder
int en ;//A7engine
//message
char data[10];
int index,panAngle,tiltAngle;
char *p;
void setup() {
  Serial.begin(9600);
  //伺服馬達PWM 8 9 10 11 12 13
  sf0.attach(8);
  sf1.attach(9);
  sf2.attach(10);
  sf3.attach(11);
  sf4.attach(12);
  sru.attach(13);
  sf0.write(90);
  sf1.write(90);
  sf2.write(90);
  sf3.write(90);
  sf4.write(90);
  sru.write(90);
  //LED
  pinMode(L0,OUTPUT);//訊號燈
  pinMode(L1,OUTPUT);//電源燈
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(L7,OUTPUT);//溫度
  digitalWrite(L1, HIGH);
  //nrf24
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
   int enn;
   if(en>=225&&en<=280){//置中
    enn=0;
    motor1.drive(0);       
    motor2.drive(0);
    digitalWrite(L5, LOW);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, LOW);
    }else if(en>=281){//倒退
    enn=-(en-281);
    motor1.drive(enn);       
    motor2.drive(enn);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    }else if(en<=225){//前進
   enn=225-en;
    motor1.drive(enn);       
    motor2.drive(enn);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, HIGH);
      }
   Serial.print("enn="); 
   Serial.println(enn); 
   sru.write(any[4]);
   sf0.write(any[0]);
   sf1.write(any[1]);
   sf2.write(any[2]);
   sf3.write(any[3]);
  digitalWrite(L0, LOW); 
  tr();
}
