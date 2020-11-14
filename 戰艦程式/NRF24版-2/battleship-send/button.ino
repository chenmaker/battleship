void button(){
  B1R= digitalRead(BU1);
  B2R= digitalRead(BU2);
  B3R= digitalRead(BU3);
  B4R= digitalRead(BU4);
if (B1R == HIGH) {
      Serial.print("B1R=");
      Serial.println(1);
      BS1=1;
    }
  else if (B1R == LOW) {
      Serial.print("B1R=");
      Serial.println(0);
      BS1=0;
    }
if (B2R == HIGH) {
      Serial.print("B2R=");
      Serial.println(1);
      BS2=1;
    }
  else if (B2R == LOW) {
      Serial.print("B2R=");
      Serial.println(0);
      BS2=0;
    }
if (B3R == HIGH) {
      Serial.print("B3R=");
      Serial.println(1);
      BS3=1;
    }
  else if (B3R == LOW) {
      Serial.print("B3R=");
      Serial.println(0);
      BS3=0;
    }
if (B4R == HIGH) {
      Serial.print("B4R=");
      Serial.println(1);
      BS4=1;
    }
  else if (B4R == LOW) {
      Serial.print("B4R=");
      Serial.println(0);
      BS4=0;
    }
 }
