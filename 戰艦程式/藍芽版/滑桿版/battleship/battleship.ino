#include <SoftwareSerial.h>//call appinventor wow
#include <Wire.h>//引用二個函式庫SoftwareSerial及Wire
SoftwareSerial BT(4,2);//定義PIN4->RX和PIN2->TX腳位  燒入前先拔除RX及TX
#include <Servo.h>
Servo sf0;
Servo sf1;
Servo sf2;
Servo sf3;
Servo sf4;
Servo sf5;
char in;
String any[40];
String all;
char ay[2];
void setup() {
  Serial.begin(9600); //Arduino起始鮑率：9600
  BT.begin(9600);
  //藍牙鮑率：57600(注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
  sf0.attach(3);
  sf1.attach(5);
  //sf2.attach(6);
 // sf3.attach(9);
 // sf4.attach(10);
 // sf5.attach(11);
  sf0.write(90);
  sf1.write(90);
  sf2.write(90);
  sf3.write(90);
  sf4.write(90);
  sf5.write(90);
 /*pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
 pinMode(13, OUTPUT); */ 
}
void loop() {
   if (BT.available()>0){
    int x;
      for(x=0;x<=3;x++){
      in=BT.read();
      any[x]=in;
      Serial.print("any"+String(x)+"=");
      Serial.println(any[x]);
      }
   if(any[3]=="0"||"1"||"2"||"3"||"4"||"5"||"6"||"7"||"8"||"9"){
    all=any[1]+any[2]+any[3];
    Serial.println("3");
    }else if(any[3]=="⸮"){      
     all=any[1]+any[2];
     Serial.println("null");
      }
    Serial.print("all=");
    Serial.println(all);
    any[0].toCharArray(ay, 2);
    Serial.print("ay0=");
    Serial.println(ay[0]+ay[1]);
    switch(ay[0]+ay[1]){
     case 'A': 
      sf0.write(all.toInt());
      Serial.println("A");
        break;
     case 'B': 
    sf1.write(all.toInt());
      Serial.println("B");
        break;
    /* case 'C': 
      sf2.write(all.toInt());
      Serial.println("C");
        break;
     case 'D': 
      sf3.write(all.toInt());
      Serial.println("D");
        break;
     case 'E': 
      sf4.write(all.toInt());
      Serial.println("E");
        break;   
     case 'O': 
      Serial.println("O");
        break;
     case 'T': 
      Serial.println("T");
        break;*/
        case 'U': 
      Serial.println("U");
       for(int i = 0; i <= 180; i+=1){
    sf0.write(i); 
    sf1.write(i);
    sf2.write(i);
    delay(20);
  }
  for(int i = 180; i >= 0; i-=1){
    sf0.write(i);
    sf1.write(i);
    sf2.write(i);
    delay(20);
  }
        break;
    }
    /*if(any[0]=="A"){
      sf0.write(all.toInt());
      }else if(any[0]=="B"){
        sf1.write(all.toInt());
        }*/
   }
}
