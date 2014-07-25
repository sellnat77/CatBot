#include <Servo.h>

Servo vert; 
Servo hor;

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
  
  migrateImpatient(hor,70,5);
  migrateImpatient(vert,125,5);
}

void migrate(Servo &myServo, int newPos) {
  int wait=random(0,30); //randomize the wait to make it more interesting
  int pos = myServo.read(); //Read the current servo position
  if (pos < newPos) { 
    for (int i=pos; i < newPos; i++) {
      myServo.write(i);
      delay(wait); 
    }
  } else { 
    for (int i=pos; i > newPos; i--) { 
      myServo.write(i);
      delay(wait);
    }
  }
}

void migrateImpatient(Servo &myServo, int newPos, int waitTime) {
  int pos = myServo.read(); //Read the current servo position
  if (pos < newPos) { 
    for (int i=pos; i < newPos; i++) {
      myServo.write(i);
      delay(waitTime); 
    }
  } else { 
    for (int i=pos; i > newPos; i--) { 
      myServo.write(i);
      delay(waitTime);
    }
  }
}
    
  
void randomPosition() {
  int rand=random(40,100); //The range is limited to 60 deg for better cat action
  migrate(hor, rand);
  
  rand=random(100,150); //The vertical range is limited to 45 deg also for better cat action. 
  migrate(vert, rand);
}
   
void loop() { 
  int rand = random(100,750);
  
  randomPosition();
  delay(rand);
}


