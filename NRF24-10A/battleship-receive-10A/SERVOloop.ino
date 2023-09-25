void SERVOloop(){
  if (ServoSwitch==true){
   s1=(any[3]*7.4349)+500;
   sf1.writeMicroseconds(s1);
   s2=(any[4]*7.4349)+500;
   sf2.writeMicroseconds(s2);
   s3=(any[5]*7.4349)+500;
   sf3.writeMicroseconds(s3);
   /*s4=(any[6]*7.4349)+500;
   sf4.writeMicroseconds(s4);
   s5=(any[7]*7.4349)+500;
   sf5.writeMicroseconds(s5);
   s6=(any[8]*7.4349)+500;
   sf6.writeMicroseconds(s6);*/  
   }else if(ServoSwitch=false){
            sf1.write(any[3]);
            sf2.write(any[4]);
            sf3.write(any[5]);
            //sf4.write(any[6]);
            //sf5.write(any[7]);
            //sf6.write(any[8]);
   }
}
