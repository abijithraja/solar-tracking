#include <Servo.h>
Servo servohori; 
int servoh = 0; 
int servohLimitHigh = 180; 
int servohLimitLow = 10;   
Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 180;
int servovLimitLow = 10;
int ldrtopr = 1; 
int ldrtopl = 2;
int ldrbotr = 0; 
int ldrbotl = 3; 
 void setup () 
 {
  servohori.attach(10); 
  servohori.write(0);
  servoverti.attach(9); 
  servoverti.write(0);
  delay(500); 
 }
void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  int topl = analogRead(ldrtopl); 
  int topr = analogRead(ldrtopr); 
  int botl = analogRead(ldrbotl); 
  int botr = analogRead(ldrbotr); 
  int avgtop = (topl + topr) / 2;
  int avgbot = (botl + botr) / 2; 
  int avgleft = (topl + botl) / 2; 
  int avgright = (topr + botr) / 2; 
  if (avgtop < avgbot)
  {
    servoverti.write(servov -1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(8);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov +1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(8);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh -1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(8);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh +1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(8);
  }
  else 
  {
    servohori.write(servoh); 
  }
  delay(50);
}
