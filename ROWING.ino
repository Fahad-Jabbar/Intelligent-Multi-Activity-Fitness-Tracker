void Rowing(){
 
 if (s>1900 && s<2020 && y>1000 && speedd == 'c')                              //rowing activity
  {
     j=0;
    z=z+1; sm=0;                             // uper range count of rowing
    SerialBT.println("Upper");
    }

 if (s>1650 && s<1870 && y>1000 && speedd == 'c')
    {
      sm=0;
    SerialBT.println("Lower");
    t=t+1;                               // lower range count of rowing
    }

 if (z==t && sm<1 && j==0){                              //if both lower and uper count are equal
      if (z>1 && t>1){
     SerialBT.println("ROWING");
     Serial.println("ROWING");
     z=0;t=0;yoga=0;sm=0;swm=0;wl=0;wu=0;j=0;}}

     
 if (z!=t){                              // if counts of rowing are not equal
      if (z>3 || t>3){
        z=0;                              // clear the count values to re-count again
        t=0;}}



  
}
