void wrong(){
 if(s==0){
  lcd.setCursor(0,1); 
  lcd.print("225<en<280");
  if(en<100){
    lcd.setCursor(15,1);
    lcd.print(" ");
    }
  if(en<10){
    lcd.setCursor(14,1);
    lcd.print(" ");
    }
    lcd.setCursor(10,1);
    lcd.print("en:");
    lcd.print(en); 
  
  lcd.setCursor(0,0); 
  lcd.print("85<ru<95");
  if(ru<100){
    lcd.setCursor(15,0);
    lcd.print(" ");
    }
  if(ru<10){
    lcd.setCursor(14,0);
    lcd.print(" ");
    }
    lcd.setCursor(10,0); 
    lcd.print("ru:");   
    lcd.print(ru); 
  if(en<=225&&en>=280&&ru<=85&&ru>=95){
    s=0;     
    }
    else if(en>=225&&en<=280&&ru>=85&&ru<=95){      
    s=1;
    lcd.clear();
        }
    }
  }
