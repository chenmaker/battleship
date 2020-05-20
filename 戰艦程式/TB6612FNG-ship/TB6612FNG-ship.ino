#include <SparkFun_TB6612.h>

#define AIN1 5   // 控制輸入A1
#define AIN2 6   // 控制輸入A2
#define BIN1 4  // 控制輸入B1
#define BIN2 3   // 控制輸入B2
#define PWMA 7
#define PWMB 2
#define STBY 25  // 「待機」控制接Arduino的11腳

const int offsetA = 1;  // 正反轉設定A，可能值為1或-1。
const int offsetB = 1;  // 正反轉設定B，可能值為1或-1。

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {
 // 這裡沒有程式碼
}

void loop() {
   motor2.drive(100,1000);   // 驅動馬達1全速正轉1秒
   motor2.drive(-100,1000);  // 驅動馬達1全速反轉1秒
   motor2.brake();           // 停止馬達1
   delay(1000);
   
 /*  motor2.drive(255,1000);   // 驅動馬達2全速正轉1秒
   motor2.drive(-255,1000);  // 驅動馬達2全速反轉1秒
   motor2.brake();           // 停止馬達2
   delay(1000);
   
   forward(motor1, motor2, 150);  // 驅動雙馬達半速前進
   delay(1000);               // 持續1秒
   
   back(motor1, motor2, -150);  // 驅動雙馬達半速前進
   delay(1000);
   
   brake(motor1, motor2);     // 停止兩個馬達
   delay(1000);
   
   left(motor1, motor2, 100);   // 左轉
   delay(1000);
   right(motor1, motor2, 100);  // 右轉
   delay(1000);
   
   brake(motor1, motor2);     // 停止兩個馬達
   delay(1000);   */
}
