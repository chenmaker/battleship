void engine(){
  int en=255;
  int enn=255;
  if(sig==1){
    en=any[1];
    }
   if(en>=230&&en<=280){//置中
    enn=0;
    analogWrite(M1_1,0);
    analogWrite(M1_2,0);
    analogWrite(M2_1,0);
    analogWrite(M2_2,0);
    } 
   if(en>=281){//倒退
    enn=en-281;
    analogWrite(M1_1,0);
    analogWrite(M1_2,enn);
    analogWrite(M2_1,0);
    analogWrite(M2_2,enn);
    }
   if(en<=229){//前進
    enn=229-en;
    analogWrite(M1_1,enn);
    analogWrite(M1_2,0);
    analogWrite(M2_1,enn);
    analogWrite(M2_2,0);
      }
   //Serial.print("en="); 
  // Serial.println(en); 
   //Serial.print("enn="); 
  // Serial.println(enn); 
   sru1.write(any[2]);
   //sru2.write(any[2]);
  }
