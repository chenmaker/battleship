void fortPWM(){ 
  if(any[6]==0){
    }
   else if(any[6]==1){
    if(i<=180&&g==0){
      i+=7.4349;
      sf0.write(i);
      sf1.write(i);
      sf2.write(i);
      if(i>=180){
        g=1;
        }
      }else if(i>=0&&g==1){
        i-=1;
        sf0.write(i);
        sf1.write(i);
        sf2.write(i);
           if(i<=0){
             g=0;
             }
        }
        Serial.print("i=");
        Serial.println(i);
       }
    }
