int c=0;
void mg(){
   do{
      commaPosition = message.indexOf(';');
      if(commaPosition != -1)
      {
         //Serial.println(message.substring(0,commaPosition));
         if(e<=20){
         any[e]=message.toInt();
         Serial.print("any["+String(e)+"]=");
         Serial.println(any[e]);
         if(any[1]==0){
         e+=1;
         if(e>=11){
            e=1;
            }
           }else if(any[1]==1){
            if (c==0){
            e=11;}
            if(e<=19){
            e+=1;
            c=1;
            }else if(e>=20){
               e=1;
               c=0;
                }            
            }
         }
         message=message.substring(commaPosition+1,message.length());  
      }
      else{
        if(message.length()>0){
         //  Serial.println(message);
        }
      }
   } 
   while(commaPosition>=0);
  }
