void WLift(){
  if (speedd =='a'){
 if (y<2350 && y>2100 )                                //weight-lifting
  {                 
    wl=wl+1;                           
    t=0; z=0;
    }

    if (y>1450 && y<1600)
    {
    j=0;                        
    wu=wu+1;                          
    sm=0;t=0; z=0; 
    }

     if (wl==wu){                 
      if (wl>1 && wu>1){
     SerialBT.println("Weight Lifting");
       Serial.println("Weight Lifting");
    
  z=0; t=0; yoga=0; sm=0; swm=0; wl=0; wu=0; j=0;}}

       if (wl!=wu){                               // if counts are not equal
      if (wl>3 || wu>3){
        z=0;                                     // clear the count values to re count again
        t=0;
        wl=0; wu=0;}}


  }
}
