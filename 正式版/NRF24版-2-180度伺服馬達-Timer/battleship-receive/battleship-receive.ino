#include <Timer.h>//計時器
#include <SPI.h>
#include "RF24.h"//nrf24
#include <SparkFun_TB6612.h>//馬達控制
#include <Thermistor.h>//溫度
#include <Servo.h>//伺服馬達
Servo sf0,sf1,sf2,sf3,sf4,sru;
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
int e;//接受資料分段大小
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
int en=255;//A7engine
int enn=255;//引擎
int sig=0;
//message
char data[20];
int index,panAngle,tiltAngle;
char *p;
Timer tcb;//計時器
int i=500,g=0;
void setup() {
  Serial.begin(9600);
  tcb.every(10, fortPWM); //每10ms 執行副程式
  //伺服馬達PWM 8 9 10 11 12 13
  sf0.attach(8);
  sf1.attach(9);
  sf2.attach(10);
  sf3.attach(11);
  sf4.attach(12);
  sru.attach(13,400,2400);
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
  rf24.setPALevel(RF24_PA_MAX);   //通訊強度
  rf24.setDataRate(RF24_2MBPS);   //傳輸速率
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
  Serial.println("nRF24L01 ready!");
  any[0]=90;//A0fort0    8
  any[1]=90;//A1fort1    9
  any[2]=90;//A2fort2   10
  any[3]=90;//A3fort3   11
  any[4]=90;//A4fort4   12
  any[5]=255;//A6rudder 13
  any[6]=0;//SWITCH
  any[7]=0;//SWITCH
  any[8]=0;//SWITCH
  any[9]=0;//SWITCH
}

void loop() {   
  while (rf24.available(&pipe)) {
    char msg[40]="";
    rf24.read(&msg, sizeof(msg));
    Serial.println(msg); // 顯示訊息內容 
    for(int i=0;i<=40;i++){
      message+=msg[i];
      //Serial.println(message); 
      digitalWrite(L0, HIGH);
      //sig=0;
      }
   }
   /*sig=1;
   if(sig==1){
    any[5]=255;
    }*/   
   mg();//訊息
   engine();//引擎
   sru.write(any[4]);
   sf0.write(any[0]);
   sf1.write(any[1]);
   sf2.write(any[2]);
   sf3.write(any[3]);
  digitalWrite(L0, LOW); 
  tr();//溫度
  SwitchAction();//開關
}
