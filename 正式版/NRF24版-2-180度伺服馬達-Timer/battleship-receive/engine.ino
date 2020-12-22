void engine(){
  en=any[5];
   if(en>=225&&en<=280){//置中
    enn=0;
    motor1.drive(0);       
    motor2.drive(0);
    digitalWrite(L5, LOW);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, LOW);
    } 
   if(en>=281){//倒退
    enn=-(en-281);
    motor1.drive(enn);       
    motor2.drive(enn);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, LOW);
    digitalWrite(L7, LOW);
    }
   if(en<=225){//前進
    enn=225-en;
    motor1.drive(enn);       
    motor2.drive(enn);
    digitalWrite(L5, LOW);
    digitalWrite(L6, LOW);
    digitalWrite(L7, HIGH);
      }
   Serial.print("enn="); 
   Serial.println(enn); 
  
  
  }
