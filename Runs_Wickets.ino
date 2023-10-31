// LAst Two Pannels ///

#include <SPI.h>
#include <DMD2.h>
 
#include <fonts/Arial_Black_16.h>


SoftDMD dmd(7,1); 



float runs = 0.0;
int wickets = 0;
float rate = 0.0;

void setup() {

  Serial.begin(57600);
  dmd.setBrightness(255);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();

  dmd.drawString(128,0,F("PANEL BY"));
  dmd.drawString(32,0,F("RAAM"));
  delay(1500);
  dmd.clearScreen();
    dmd.drawString(128,0,F("PANEL BY"));
  dmd.drawString(32,0,F("RAAM"));
    delay(1500);
  dmd.clearScreen();
    dmd.drawString(128,0,F("PANEL BY"));
  dmd.drawString(32,0,F("ANJANA"));
  delay(1500);
  dmd.clearScreen();
    dmd.drawString(128,0,F("PANEL BY"));
  dmd.drawString(32,0,F("JOHN"));
    delay(1500);
  dmd.clearScreen();
    dmd.drawString(128,0,F("PANEL BY"));
  dmd.drawString(32,0,F("RODRIGO"));
    delay(1500);
  dmd.clearScreen();
    dmd.drawString(128,0,F("LOADING"));
  dmd.drawString(32,0,F("."));
   delay(500);
    dmd.drawString(32,0,F(".."));
    delay(1000);
    dmd.drawString(32,0,F("..."));
    delay(1000);
    dmd.drawString(32,0,F("...."));
    delay(1000);
    dmd.drawString(32,0,F("....."));
  delay(1000);
  dmd.drawString(32,0,F("......"));
  delay(1000);
  dmd.drawString(32,0,F("......."));
  delay(1000);
  dmd.drawString(32,0,F("........"));
  delay(1000);
  dmd.drawString(32,0,F("........."));
  delay(1000);
  dmd.clearScreen();
    dmd.drawString(32,0,F("DONE !"));
    delay(1000);
    dmd.clearScreen();
}

// the loop routine runs over and over again forever:
void loop() {

char Cruns[3];

String Sruns;

Sruns=String(runs);

Sruns.toCharArray(Cruns,3); 

char Cwickets[4];

String Swickets;

Swickets=String(rate);

Swickets.toCharArray(Cwickets,4); 


  String mystring = String(runs); // Transform Counter Int to String for manipulation
            
    

  dmd.drawString(32,0,F("WICKS"));
  dmd.drawString(128,0,F("RUNS"));
  dmd.drawString(88,0,Swickets);
  dmd.drawString(192,0,Sruns);
  
rate = wickets/runs;

char a = Serial.read();


if(a == 'R')
{
  runs = runs + 1;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'r')
{
  runs = runs - 1;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'W')
{
  wickets++;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'w')
{
  wickets--;
  Serial.flush();
  dmd.clearScreen();
}



if(a == ' ')
{
 wickets = 0;

  runs = 0;
  dmd.clearScreen();
}
 



  
}
