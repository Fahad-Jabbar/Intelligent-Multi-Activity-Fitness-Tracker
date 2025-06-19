#include <EEPROM.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#include <Wire.h>                                         //I2C communication (SDA, SCL pins)
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1013.25
Adafruit_BMP085 bmp;






BluetoothSerial SerialBT;
String pass="123456";
String str;
char speedd = 'a';
int x;                  // variable for storing sensor value
int y=0;                     // variable for storing sensor value
int s=0;                          //variable for x-value of sensor-1
int sensx1=4;                 // x-axis of sensor-1
int sensy1=2;                   // y-axis of sensor-1
int sensy2=15;                    //y-axis of sensor-2
int pulse=5;           //pulse count pin
///////////////////////
////////////////////////////////////
int z=0;                 // rowing lower range
int t=0;          // rowing upper range
int j=0;                // variable for jump count
int wl=0;         //weightlifting lower variable
int wu=0;             //weightlifting upper range variable
int sm=0;                  //swimming 
int swm=0;
int yoga;
int row=0;
////////////////////
/////////////////////////////
int wl_count=0;
int wu_count=0;
///////////////////////////////////////////
////////////////////////////
////////////////
int T;                                //temperature
int P;                      //pressure
int rAlti;              //real-altitude
int Alt;                   //altitude variable for direct reading from Altimeter
int Sp;                    //sea-level presure 
int alt;                        //variable of altitude use in climbing
int altr; 
int altr2;          //lower offset and upper offset of altitude
/////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////////////////////
const unsigned long delaytime=15000;     //15 sec delay time for pulse count
unsigned long prev=0;     
int pulseread; 
long pulsecount=0;                //pulse count





void setup() {
  Serial.begin(9600);
//  EEPROM.begin(512);
  SerialBT.begin("MERA BLUETOOTH");                        //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(sensy1,INPUT);
  pinMode(sensy2,INPUT);
  pinMode(sensx1,INPUT);
  pinMode(pulse,INPUT);
//   EEPROM.write(sc_eeprom,0);
//   EEPROM.write(s_eeprom,0);
                                                  
//if (!bmp.begin()) {
//  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
//  while (1) {}}
  
rAlti=(bmp.readAltitude(seaLevelPressure_hPa * 100));  //reading altitude of BMP sensor
   altr=rAlti+2;                                            //offset for upper altitude
   altr2=rAlti-2;                   //offset for lower altitude
}


void loop() { 
 
 // Pulsecounter();  
 //////////////////////////////////////////////////////////////////////
 //////////////////////Getting Incoming Data /////////////////////////
 /////////////////////////From Bluetooth/////////////////////////////
  
  if (SerialBT.available()) {
    str=SerialBT.readString();str.toUpperCase();                        //reading data from bluetooth app and Capitalizing
    Serial.print ("Received:  ");Serial.println(str);                      //print on serial monitor
    int len=str.length();                                               //calculating length
    Serial.print("len = ");Serial.println(len);}
    
////////////////////////////////////////////////////////////////
////////////////////////BMP reading///////////////////////////////
///////////////////////////////////////////////////////////////

    T=(bmp.readTemperature());
    P=(bmp.readPressure());
    Alt=(bmp.readAltitude());
    Sp=(bmp.readSealevelPressure());
    rAlti=(bmp.readAltitude(seaLevelPressure_hPa * 100));
    alt=rAlti;

//////////////////////////////////////////////////////////////////////
//////////////////////////Sensor Reading ////////////////////////////
//////////////////////////////////////////////////////////////////////

      s=analogRead(sensx1);    //reading x-axis of sensor1
      Serial.print(" sx : "); Serial.print(s);  
      SerialBT.print(" sx : "); SerialBT.print(s);

       
     x= analogRead(sensy1); // reading y-axis of sensor1
     Serial.print("  y1 : "); Serial.print(x); 
     SerialBT.print("  y1 : "); SerialBT.print(x);


  
     y= analogRead(sensy2); // reading y-axis of sensor2
     Serial.print("  y2 : ");  Serial.println(y);
     SerialBT.print("  y2 : "); SerialBT.println(y);



///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////Conditions//////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
delay(500);
climbing();
Rowing();

////////////////////////////
WLift();
/////////////////////////////////////

Swimming();
Jumping();
Yoga();
/////////////////////////////////////////////////////////////////////////////////////////////////////////



 if (str.startsWith("@IN")) {                               //when we write @IN it show below values on app

               SerialBT.print("Temperature = ");SerialBT.println(T);
               SerialBT.print("Pressure = ");   SerialBT.println(P);
               SerialBT.print("Altitude = ");   SerialBT.println(Alt);
               SerialBT.print("Pressure at sealevel (calculated) = "); SerialBT.println(Sp);
               SerialBT.print("Real altitude = ");SerialBT.println(rAlti);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}
if (str.startsWith("STANDING")){speedd='a';}              // SerialBT.println("Still");
if (str.startsWith("WALKING")){speedd='b';SerialBT.println("Walking");}
if (str.startsWith("RUNNING")){speedd='c';SerialBT.println("Running");}
if (str.startsWith("CYCLING")){speedd='d';SerialBT.println("Cycling");}              
}
