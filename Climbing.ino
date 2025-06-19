void climbing(){

  
if (alt-altr>1)                               //altitude is greater than real-altitude
{ j=0;                                      //jumping=0
  SerialBT.println("Climbing UP");
 altr2++;                                   //increasing lower refernce altitude
  altr=altr2+2;                             //increasing upper refernce altitude
  alt=altr;                                 //When person is in standing postion after climbing up
z=0;t=0;yoga=0;sm=0;swm=0;wl=0;wu=0;j=0;
}

if (altr2-alt>1)                               //altitude is lower than real-altitude
{ j=0;                                       //jumping=0
   SerialBT.println("Climbing Down");
  altr2--;                                   //increasing lower refernce altitude
  altr=altr2+2;                              //increasing upper refernce altitude
z=0;t=0;yoga=0;sm=0;swm=0;wl=0;wu=0;j=0;}

}
