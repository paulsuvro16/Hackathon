const int trigger1 = 9; //Trigger pin of 1st Sesnor
const int echo1 =10; //Echo pin of 1st Sesnor
const int trigger2 = 11; //Trigger pin of 2nd Sesnor
const int echo2 = 12;//Echo pin of 2nd Sesnor

long time_taken;
int dist,distL,distR;
 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

/*###Func1`tion to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>60)
dist = 60;
}

void loop() 
{ 
calculate_distance(trigger1,echo1);
distL =dist;
Serial.print("Left-");
Serial.println(distL);
calculate_distance(trigger2,echo2);
distR =dist;
Serial.print("Right-");
Serial.println(distR);
if ((distL >10 && distR>10) && (distL <30 && distR<30))
{
  Serial.println("Play/Pause"); 
  delay (500);
}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

 

//Control Modes
//Lock Left - Control Mode
if (distL>=5 && distL<=18)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=5 && distL<=18)
  {
    Serial.println("Left Locked");
    while(distL<=58)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<13) //Hand pushed in 
      {Serial.println ("Volume Increased "); delay (300);}
      if (distL>16) //Hand pulled out
      {Serial.println ("Volume Decreased "); delay (300);}
    }
  }
}

//Lock Right - Control Mode
if (distR>=5 && distR<=18)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=5 && distR<=18)
  {
    Serial.println("Right Locked");
    while(distR<=58)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<13) //Right hand pushed in
      {Serial.println ("Rewind"); delay (300);}
      if (distR>16) //Right hand pulled out
      {Serial.println ("Forward"); delay (300);}
  }
}
}

delay(200);
}
