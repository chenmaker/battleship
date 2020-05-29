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
Servo sf5;
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
int L0=46,L1=44,L2=47,L3=45,L4=43,L5=23,L6=25,L7=27;
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
  Serial.begin(9600);
  //PWM 8 9 10 11 12 13 44 45 46
  sf0.attach(45);
  sf1.attach(12);
  sf2.attach(11);
  sf3.attach(10);
  sf4.attach(9);
  sf5.attach(8);
  sru.attach(13);
  sru.write(90);
  sf0.write(90);
  sf1.write(90);
  sf2.write(90);
  sf3.write(90);
  //LED
  pinMode(L0,OUTPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(L7,OUTPUT);
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
   if(en<=270&&en>=230){
    enn=0;
    motor1.drive(0);       
    motor2.drive(0);
    }else if(en>=271){
   enn=-(en-271);
    motor1.drive(enn);       
    motor2.drive(enn);
    }else if(en<=229){
    enn=229-en;
       motor1.drive(enn);       
       motor2.drive(enn);
      }
   Serial.print("enn="); 
   Serial.println(enn); 
   //delay(1000);
   sru.write(any[4]);
   sf0.write(any[0]);
   sf1.write(any[1]);
   sf2.write(any[2]);
   sf3.write(any[3]);
  //sf4.write(any[4]);
  //sf5.write(any[5]);
  digitalWrite(L0, LOW); 
  Serial.print("The sensor temperature is: ");
  Serial.print(temperature);
  Serial.println("C");
  Serial.print("The sensor temperature1 is: ");
  Serial.print(temperature1);
  Serial.println("C");
  if(temperature>40){digitalWrite(L2, HIGH);
  }else if(temperature<50&&temperature>40){digitalWrite(L3, HIGH);
  }else if(temperature>50){digitalWrite(L4, HIGH);}
   if(temperature1>40){digitalWrite(L5, HIGH);
  }else if(temperature1<50&&temperature1>40){digitalWrite(L6, HIGH);
  }else if(temperature1>50){digitalWrite(L7, HIGH);}

}
