#include <Servo.h>
//Initialize the servos
Servo vert; 
Servo hor;

//Associate the servos with the digital inputs
//Draw the bounding areas only 3 times
void setup() { 
  vert.attach(8);
  hor.attach(9); 
  
  int x = 0;
  
  do
  {
    migrateImpatient (vert,100,30);
    migrateImpatient (hor ,40 ,30);
    migrateImpatient (vert,150,30);
    migrateImpatient (hor ,100,30);
    
    x++;
  }while(x < 3);
  
  migrateImpatient(hor ,70 ,5);
  migrateImpatient(vert,125,5);
}

void migrate(Servo &myServo, int newPos) 
{
  //Random wait time
  int wait=random(0,30); 
  
  //Get current position of servos
  int pos = myServo.read();
  
  if (pos < newPos) 
  { 
    for (int i=pos; i < newPos; i++) 
    {
      myServo.write(i);
      delay(wait); 
    }
  } 
  else 
  { 
    for (int i=pos; i > newPos; i--) 
    { 
      myServo.write(i);
      delay(wait);
    }
  }
}

//Same function as above but code can specify a wait time 
//Used for the initial bounding sector
void migrateImpatient(Servo &myServo, int newPos, int waitTime) 
{
  int pos = myServo.read();
  
  if (pos < newPos) 
  { 
    for (int i=pos; i < newPos; i++) 
    {
      myServo.write(i);
      delay(waitTime); 
    }
  } 
  else 
  { 
    for (int i=pos; i > newPos; i--) 
    { 
      myServo.write(i);
      delay(waitTime);
    }
  }
}
    
//Generates random coordinates  
void randomPosition() 
{
  //Horizontal servo is limited to 60 degrees
  int rand=random(40,100); 
  migrate(hor, rand);
  
  //The vertical range is limited to 50 degrees
  rand=random(100,150); 
  migrate(vert, rand);
}
   
//Carries out the random movements with varied wait times
void loop() 
{ 
  //Specifies the wait time between each new set of coords
  //Currently between 100ms-750ms
  int rand = random(100,750);
  
  randomPosition();
  delay(rand);
}


