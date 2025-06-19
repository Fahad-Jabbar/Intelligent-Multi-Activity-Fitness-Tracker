//swimming

     void Swimming(){

      if ((s<1500 || s>2020) && (speedd == 'b')){
      
      sm=sm+1;
      t=0; z=0;                // clear the count values to re-count again
      SerialBT.println(sm);
      
      }
      
  if (sm>1)
  {SerialBT.println("Swimming");sm=0; j=0; t=0; z=0; wl=0; wu=0;}


}
