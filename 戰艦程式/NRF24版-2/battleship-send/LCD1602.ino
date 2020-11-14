void LCD1602(){
  if(f0<100){
    lcd.setCursor(4,0);
    lcd.print(" ");
    }
  if(f0<10){
    lcd.setCursor(3,0);
    lcd.print(" ");
    }
    lcd.setCursor(0,0); 
    lcd.print("1:");   
    lcd.print(f0);

  if(f1<100){
    lcd.setCursor(9,0);
    lcd.print(" ");
    }
  if(f1<10){
    lcd.setCursor(8,0);
    lcd.print(" ");
    }
    lcd.setCursor(5,0); 
    lcd.print("2:");   
    lcd.print(f1);

  if(f2<100){
    lcd.setCursor(4,1);
    lcd.print(" ");
    }
  if(f2<10){
    lcd.setCursor(3,1);
    lcd.print(" ");
    }
    lcd.setCursor(0,1); 
    lcd.print("3:");   
    lcd.print(f2);

  if(f3<100){
    lcd.setCursor(9,1);
    lcd.print(" ");
    }
  if(f3<10){
    lcd.setCursor(8,1);
    lcd.print(" ");
    }
    lcd.setCursor(5,1); 
    lcd.print("4:");   
    lcd.print(f3);
  
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
  }
