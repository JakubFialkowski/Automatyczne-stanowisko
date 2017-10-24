#include "HX711.h"
 
#define calibration_factor -2390000  //Odczytana wartość z programu kalibracyjnego
 
#define DOUT  4          //pin 3 Arduino i wyjście DAT czujnika
#define CLK  3           //pin 2 Arduino i wyjście CLK czujnika
 
HX711 scale(DOUT, CLK);
 float vPow = 5;
 float r1 = 103700;
 float r2 = 9370;

 volatile byte REV; 
 //double rpm;//  VOLATILE DATA TYPE TO STORE REVOLUTIONS
 
//unsigned long int rpm, maxRPM;  //  DEFINE RPM AND MAXIMUM RPM
 
unsigned long time;         //  DEFINE TIME TAKEN TO COVER ONE REVOLUTION
 
int ledPin = 12;           //   STATUS LED
 
int led = 0,RPMlen , prevRPM;  //  INTEGERS TO STORE LED VALUE AND CURRENT RPM AND PREVIOUS RPM
 
int flag = 0;             //  A VARIABLE TO DETERMINE WHETHER THE LCD NEEDS TO BE CLEARED OR NOT

long prevtime = 0;       //  STORE IDLE TIME TO TOGGLE MENU
    
 int val;
long last=0;
int stat=LOW;
int stat2;
int contar=0;

int sens=75;  // this value indicates the limit reading between dark and light,
              // it has to be tested as it may change acording on the 
              // distance the leds are placed.
int nPalas=1; // the number of blades of the propeller

int milisegundos=500; // the time it takes each reading
 
void setup() {
  Serial.begin(9600);
 
  //attachInterrupt(0, RPMCount, RISING);     //  ADD A HIGH PRIORITY ACTION ( AN INTERRUPT)  WHEN THE SENSOR GOES FROM LOW TO HIGH
     
     REV = 0;      //  START ALL THE VARIABLES FROM 0
     
    // rpm = 0;
     
     time = 0;
  scale.set_scale(calibration_factor); //Ustawienie kalibracji
  scale.tare();                        //Zerowanie wskazania na początek
 
   pinMode(13,OUTPUT);
}
 
void loop() {

val=analogRead(5);
  if(val<sens)
    stat=LOW;
   else
    stat=HIGH;
   digitalWrite(13,stat); //as iR light is invisible for us, the led on pin 13 
   double rpm;                       //indicate the state of the circuit.

   if(stat2!=stat){  //counts when the state change, thats from (dark to light) or 
                     //from (light to dark), remmember that IR light is invisible for us.
     contar++;
     stat2=stat;
   }
   





  
  // long currtime = millis();                 // GET CURRENT TIME
  
 // long idletime = currtime - prevtime;        //  CALCULATE IDLE TIME
    
    
     
             
  
     
    // rpm = (30*1000/(millis() - time)*REV)*1.75;       //  CALCULATE  RPM USING REVOLUTIONS AND ELAPSED TIME
     
                                //  GET THE MAX RPM THROUGHOUT THE RUN
    
   //  time = millis();                            
     
   //  REV = 0;
     
   //  int x= rpm;                                //  CALCULATE NUMBER OF DIGITS IN RPM
   //  while(x!=0)
  //   {
   //    x = x/10;
   //    RPMlen++;
   //  }       
          
     
     
  //   if(RPMlen!=prevRPM)                             // IF THE RPM FALLS TO A LOWER NUMBER WITH LESS DIGITS , THE LCD WILL GET CLEARED
  //   {
       
   //    prevRPM = RPMlen;
   //    flag=0;
       
   //  }
     
   
  
     
   //  prevtime = currtime; 
unsigned int x1=0;
float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x1 = 0; x1 < 150; x1++){ //Get 150 samples
  AcsValue = analogRead(A0);     //Read current sensor values   
  Samples = Samples + AcsValue;  //Add samples together // let ADC settle before next sample 3ms
}
AvgAcs=Samples/150.0;//Taking Average of Samples


AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.066;

float v = (analogRead(A1) * vPow) / 1024.0;
   float v2 = v / (r2 / (r1 + r2));

//float Acsrpm=0.0,Samples1=0.0,Avgrpm=0.0,AcsrpmF=0.0;
    // for (int x2 = 0; x2 < 150; x2++){ //Get 150 samples
 // Acsrpm = rpm;     //Read current sensor values   
  //Samples1 = Samples1 + Acsrpm;  //Add samples together // let ADC settle before next sample 3ms
//}
//Avgrpm=Samples1/150.0;//Taking Average of Samples
int czas =0;
if (scale.get_units()>0.005){
czas= millis()/100;
}
else
{
  czas=0;
}
if(millis()-last>=milisegundos){
     double rps=((double)contar/nPalas)/2.0*1000.0/milisegundos;
     rpm=((double)contar/nPalas)/2.0*60000.0/(milisegundos);
    
    Serial.print(rpm);
    
     contar=0;
     last=millis();
   }


//Serial.print(czas);                       
     
     
    
     Serial.print("  ");
      Serial.print(rpm);                        //  PRINT RPM IN DECIMAL SYSTEM
     
     
    // Serial.print("RPM");
     Serial.print("  ");
   
   
   Serial.print(v2);
   //Serial.print(" V");
Serial.print("  ");

Serial.print(AcsValueF);
//Serial.print(" A");
Serial.print("  ");//Print the read current on Serial monitor
  
  
  Serial.println(scale.get_units(), 3);    //scale.get_units() zwraca zmienną float
 // Serial.print(" kg");                   //Dowolnie możemy wybrać kilogramy lub funty, lecz przy zmianie zmienia się również współczynnik kalibracji
  //Serial.println();

  //delay(100);
  
}

 void RPMCount()                                // EVERYTIME WHEN THE SENSOR GOES FROM LOW TO HIGH , THIS FUNCTION WILL BE INVOKED 
 {
   REV++;                                         // INCREASE REVOLUTIONS
   
   
 }
