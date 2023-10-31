

#include <SPI.h>
#include <DMD2.h>
 
#include <fonts/Arial_Black_16.h>


SoftDMD dmd(6,1); 



int balls = 120;
int target = 0;
int targe = 0;
int runs = 0;

void setup() {

  Serial.begin(57600);
  dmd.setBrightness(255);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();


  
  dmd.drawString(0,0,F("CADETS "));
  dmd.drawString(96,0,F("KDU ENG"));
 
 delay(20000);
  dmd.clearScreen();

}

// the loop routine runs over and over again forever:
void loop() {

char Cballs[3];

String Sballs;

Sballs=String(balls);

Sballs.toCharArray(Cballs,3); 

char Ctarget[3];

String Starget;

Starget=String(targe);

Starget.toCharArray(Ctarget,3); 




  dmd.drawString(177,0,F("IN "));
  dmd.drawString(96,0,F("NEED"));
  dmd.drawString(0,0,Sballs);
    dmd.drawString(33,0,F("BALLS"));
  dmd.drawString(142,0,Starget);
  


char a = Serial.read();


if(a == 'B')
{
  balls--;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'b')
{
  balls++;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'T')
{
  target++;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 't')
{
  target--;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'R')
{
  runs++;
  Serial.flush();
  
}

if(a == 'r')
{
  runs--;
  Serial.flush();
  
}



if(a == ' ')
{
 
 targe = 0;
   runs = 0;
  target = 0;
  balls = 120;
  dmd.clearScreen();
}





targe = target-runs;



  
}
