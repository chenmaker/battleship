#include <SoftwareSerial.h>
SoftwareSerial BT(4,2);//定義PIN4->RX和PIN2->TX腳位  燒入前先拔除RX及TX
#include <Servo.h>
Servo sf0;
Servo sf1;
Servo sf2;
Servo sf3;
Servo sf4;
Servo sf5;
int s0=90,s1=90,s2=90,s3=90,s4=90,s5=90;
void setup() {
  Serial.begin(9600); //Arduino起始鮑率：9600
  BT.begin(115200);
  //sf0.attach(3);
  sf0.attach(3);
  sf1.attach(5);
  sf2.attach(10);//6
 // sf3.attach(9);
 // sf4.attach(10);
 // sf5.attach(11);
  sf0.write(s0);
  sf1.write(s1);
  sf2.write(s2);
  sf3.write(s3);
  sf4.write(s4);
  sf5.write(s5);
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
   switch(BT.read()){
     case 'A': 
      s0+=1;
     // Serial.println("A");
        break;
     case 'B': 
      s0-=1; 
     // Serial.println("B");
        break;
     case 'C': 
      s1+=1;
      ///Serial.println("C");
        break;
     case 'D': 
      s1-=1;
     // Serial.println("D");
        break;
     case 'E':
      s2+=1; 
     // Serial.println("E");
        break;
     case 'F': 
      s2-=1;
     // Serial.println("F");
        break;           
    /* case 'O': 
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
    }delay(10);
      sf0.write(s0);
      sf1.write(s1);
      sf2.write(s2);
      Serial.print("s0=");
      Serial.println(s0);
      Serial.print("s1=");
      Serial.println(s1);
      Serial.print("s2=");
      Serial.println(s2);
  }
}
