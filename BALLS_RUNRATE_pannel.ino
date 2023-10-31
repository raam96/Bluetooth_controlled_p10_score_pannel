// LAst Two Pannels ///

#include <SPI.h>
#include <DMD2.h>
 
#include <fonts/Arial_Black_16.h>


SoftDMD dmd(7,1); 



float balls = 0.0;
int target = 0;
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

char Cballs[3];

String Sballs;

Sballs=String(balls);

Sballs.toCharArray(Cballs,3); 

char Ctarget[4];

String Starget;

Starget=String(rate);

Starget.toCharArray(Ctarget,4); 


  String mystring = String(balls); // Transform Counter Int to String for manipulation
            
      // Convert number to a time value
      for (int z = 0; z < 6; z++){
             
        if ( mystring.substring(z) == "0.60" ) {
          balls = (balls + 0.4);
        }        

        if ( mystring.substring(z) == "1.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "2.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "3.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "4.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "5.60" ) {
           balls = (balls + 0.4);
        }
        
        if ( mystring.substring(z) == "6.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "7.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "8.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "9.60" ) {
           balls = (balls + 0.4);
        }
        if ( mystring.substring(z) == "10.60" ) {
           balls = (balls + 0.4);
        }
          if ( mystring.substring(z) == "11.60" ) {
           balls = (balls + 0.4);
        }
        
      }



  dmd.drawString(32,0,F("RATE"));
  dmd.drawString(128,0,F("OVERS"));
  dmd.drawString(88,0,Starget);
  dmd.drawString(192,0,Sballs);
  
rate = target/balls;

char a = Serial.read();


if(a == 'B')
{
  balls = balls + 0.1;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'b')
{
  balls = balls - 0.1;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'R')
{
  target++;
  Serial.flush();
  dmd.clearScreen();
}

if(a == 'r')
{
  target--;
  Serial.flush();
  dmd.clearScreen();
}



if(a == ' ')
{
 target = 0;

  balls = 0;
  dmd.clearScreen();
}
 



  
}
