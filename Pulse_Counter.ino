void Pulsecounter(){
 unsigned long current =millis();       //function for cuurent time of ESP32
 
 pulseread=digitalRead(pulse);
    if (pulseread==HIGH)
    {
      delay(400);
      pulsecount=pulsecount+1;                          //pulse count
      delay(20);
      }
    if(current-prev>= delaytime)                        //comparing delay time for pulse count 
    { SerialBT.println(pulsecount*4);                   //4*15=60 sec
     Serial.println(pulsecount*4);
    delay(20);
    prev=current;               
    pulsecount=0;}

}
