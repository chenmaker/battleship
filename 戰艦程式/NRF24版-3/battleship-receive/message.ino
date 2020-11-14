void mg(){
   do{
      commaPosition = message.indexOf(';');
      if(commaPosition != -1)
      {
         //Serial.println(message.substring(0,commaPosition));
         if(e<=9){
         any[e]=message.toInt();
         Serial.print("any["+String(e)+"]=");
         Serial.println(any[e]);
         e+=1;
         if(e>=10){
            e=0;
            }
         }
         message=message.substring(commaPosition+1,message.length());  
      }
      else{
        if(message.length()>0){
           Serial.println(message);
        }
      }
   } 
   while(commaPosition>=0);
  }
