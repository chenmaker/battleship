void fortPWM(){ 
  if(any[6]==0){
    }
   else if(any[6]==1){
    if(i<=2500&&g==0){
      i+=7.4349;
      sf0.writeMicroseconds(i);
      sf1.writeMicroseconds(i);
      sf2.writeMicroseconds(i);
      if(i>=2500){
        g=1;
        }
      }else if(i>=500&&g==1){
        i-=7.4349;
        sf0.writeMicroseconds(i);
        sf1.writeMicroseconds(i);
        sf2.writeMicroseconds(i);
           if(i<=500){
             g=0;
             }
        }
        Serial.print("i=");
        Serial.println(i);
       }
    }
