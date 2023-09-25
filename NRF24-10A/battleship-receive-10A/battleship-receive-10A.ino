#include <Timer.h>//計時器
#include <SPI.h>
#include "RF24.h"//nrf24
#include <Servo.h>//伺服馬達
Servo sf1,sf2,sf3,sf4,sf5,sf6,sru1,sru2;
int s1,s2,s3,s4,s5,s6;
//nrf24
RF24 rf24(49,48);
const byte addr[] = "CHEN";
const byte pipe = 1;  // 指定通道編號
int commaPosition;
String message;
int any[40];
int e=1;
//LED
//int L1=3,L2=5,L3=7,L4=9,L5=11,L6=13;
const int BZ=63;//buzzer 蜂鳴器
//馬達控制腳位
const int M1_1=2,M1_2=4,M2_1=6,M2_2=8;
//啟動引擎
int sig=0;
//message
char data[20];
int index,panAngle,tiltAngle;
char *p;
Timer tcb;//計時器
int i=500,g=0;
bool  ServoSwitch=true;//true=270度伺服馬達 false=180度伺服馬達 
void setup() {
  Serial.begin(9600);
  //buzzer 蜂鳴器
  //pinMode(BZ, OUTPUT);
  digitalWrite(BZ, HIGH);
  delay(100);
  digitalWrite(BZ, LOW);
  //tcb.every(10, fortPWM); //每10ms 執行副程式,砲臺自動旋轉
  SERVO();
  //LED 訊號燈
  //pinMode(L1,OUTPUT);
  //pinMode(L2,OUTPUT);
  //pinMode(L3,OUTPUT);
  //pinMode(L4,OUTPUT);
  //pinMode(L5,OUTPUT);
  //pinMode(L6,OUTPUT);
  //digitalWrite(L1,LOW);
  //nrf24
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);
  rf24.setDataRate(RF24_2MBPS);
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
  Serial.println("nRF24L01 ready!");
  analogWrite(M1_1,0);
  analogWrite(M1_2,0);
  analogWrite(M2_1,0);
  analogWrite(M2_2,0);  
}

void loop() {   
 //tcb.update();//啟動計時器
 while (rf24.available(&pipe)) {
    char msg[40]="";
    rf24.read(&msg, sizeof(msg));
    //Serial.println(msg); // 顯示訊息內容 
    for(int i=0;i<=40;i++){
      message+=msg[i];
      //Serial.println(message); 
      //digitalWrite(L1, HIGH);
      sig=1;
      }
   }
   mg();
   engine();
   SERVOloop();//砲台控制
   //SwitchAction();//燈號
}
