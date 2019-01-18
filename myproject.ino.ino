byte leds[9][6] = {{LOW, HIGH, HIGH, HIGH, LOW, LOW},
                  {LOW, HIGH, HIGH, LOW, HIGH, LOW},
                  {LOW, HIGH, HIGH, LOW, LOW, HIGH},
                  {HIGH, LOW, HIGH, HIGH, LOW, LOW},
                  {HIGH, LOW, HIGH, LOW, HIGH, LOW},
                  {HIGH, LOW, HIGH, LOW, LOW, HIGH},
                  {HIGH, HIGH, LOW, HIGH, LOW, LOW},
                  {HIGH, HIGH, LOW, LOW, HIGH, LOW},
                  {HIGH, HIGH, LOW, LOW, LOW, HIGH}
                  };
byte pat1[4][9] = {{1,0,0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0,1,0},
                  {0,0,1,0,0,1,0,0,1},
                  {0,1,0,0,1,0,0,1,0},
                  };
byte pat2[11][9] = {{0,0,0,1,1,0,1,1,0},
                   {1,1,0,1,1,0,0,0,0},
                   {0,1,1,0,1,1,0,0,0},
                   {0,0,0,0,1,1,0,1,1},
                   {1,0,1,0,1,0,1,0,1},
                   {1,0,0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0,1,0},
                   {0,0,1,0,0,1,0,0,1},
                   {1,1,1,0,0,0,0,0,0},
                   {0,0,0,1,1,1,0,0,0},
                   {0,0,0,0,0,0,1,1,1}
                   };
byte pat3[9][9] = {{0,0,0,0,1,0,0,0,0},  // 1
                  {1,0,0,0,0,0,0,0,1},  // 2
                  {1,0,0,0,1,0,0,0,1},  // 3
                  {1,0,1,0,0,0,1,0,1},  // 4
                  {1,0,1,0,1,0,1,0,1},  // 5
                  {1,0,1,1,0,1,1,0,1},  // 6
                  {1,0,1,1,1,1,1,0,1},  // 7
                  {1,1,1,1,0,1,1,1,1},  // 8
                  {1,1,1,1,1,1,1,1,1}   // 9
                  };
byte pat4[4][9] = {{0,0,0,1,1,1,0,0,0},
                  {0,0,1,0,1,0,1,0,0},
                  {0,1,0,0,1,0,0,1,0},
                  {1,0,0,0,1,0,0,0,1}
                  };
void setup()
{ 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  clearLeds();   
  digitalWrite(2, LOW);  
  digitalWrite(5, HIGH); 
  delay(1000);
  digitalWrite(2, HIGH);  
  digitalWrite(5, LOW); 
  delay(1000);
}

void loop()
{
  for( int repeat=0; repeat<10; repeat++)
  {
    for(int i=0; i<4; i++)
    {      
      for(int j=0; j<200; j++)
      {
        printPatern(pat1[i]);
      }
    }
  }
  
  for( int repeat=0; repeat<10; repeat++)
  {
    int i = random(11);
    {      
      for(int j=0; j<250; j++)
      {
        printPatern(pat2[i]);
      }
    }
  }
  
  for( int repeat=0; repeat<1; repeat++)
  {
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
      {
        clearLeds();
        digitalWrite(i+2, LOW);
        digitalWrite(j+5, HIGH);
        delay(200);
      }
    }
  }
  
  for( int repeat=0; repeat<1; repeat++)
  {
    for(int i=0; i<9; i++)
    {      
      for(int j=0; j<200; j++)
      {
        printPatern(pat3[i]);
      }
    }
  }
  
  for( int repeat=0; repeat<10; repeat++)
  {
    for(int i=0; i<4; i++)
    {      
      for(int j=0; j<200; j++)
      {
        printPatern(pat4[i]);
      }
    }
  }  
}

void clearLeds()
{
  digitalWrite(2, HIGH);  
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);  
  digitalWrite(6, LOW);  
  digitalWrite(7, LOW);
}

void printPatern(byte* number)
{
  for(int i=0; i<9; i++)
  {
    if(number[i] == 1)
    {
      for(int j=0; j<6; j++)
      {
        digitalWrite(j+2, leds[i][j]);        
      }      
    }    

    delayMicroseconds(100);
  }
}
