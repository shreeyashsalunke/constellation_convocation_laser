
#include <Servo.h> 
#include <Math.h> 
 

int pos = 0;    // variable to store the servo position 

// Coords from Kinnet
int coordinates_x_y[6][2] = {{600,100},{400,200},{200,300},{100,500},{500,500},{300, 350}}; // Assumed some random point for humans
int laser_x = 0, laser_y = 0;
// Predefined coords
int laser_coord[12][3] = {{100,0,0},{200,0,0},{300,0,0},{400,0,0},{500,0,0},{600,0,0},{0,100,0},{0,200,0},{0,300,0},{0,400,0},{0,500,0},{0,600,0}};

//Distance from laser
// float dist[12][5] = {{0,0,0,100,0}, {1,0,0,200,0}, {2,0,0,300,0}, {3,0,0,400,0}, {4,0,0,500,0}, {5,0,0,600,0}, {6,0,0,0,100}, {7,0,0,0,200}, {8,0,0,0,300}, {9,0,0,0,400}, {10,0,0,0,500}, {11,0,0,0,500}};
float angle = 0;

// Servos (x, y)
Servo servo_control[12];  


void sort (float dist[12][5])
{
  int c, d;
  float swap, swap_2, swap_3, swap_4, swap_5;
  
  for (c = 0 ; c < 11 ; c++)
  {
    for (d = 0 ; d < 11 - c; d++)
    {
      if (dist[d][1] > dist[d+1][1]) /* For decreasing order use < */
      {
        swap       = dist[d][1];
        dist[d][1]   = dist[d+1][1];
        dist[d+1][1] = swap;
        
        swap_2       = dist[d][0];
        dist[d][0]   = dist[d+1][0];
        dist[d+1][0] = swap_2;

        swap_3       = dist[d][2];
        dist[d][2]   = dist[d+1][2];
        dist[d+1][2] = swap_3;
        
        swap_4       = dist[d][3];
        dist[d][3]   = dist[d+1][3];
        dist[d+1][3] = swap_4;
      
        swap_5       = dist[d][4];
        dist[d][4]   = dist[d+1][4];
        dist[d+1][4] = swap_5;
      
      }
    }
  }
}

void sort_2_back (float dist[12][5])
{
  int c, d;
  float swap, swap_2, swap_3, swap_4, swap_5;
  
  for (c = 0 ; c < 11 ; c++)
  {
    for (d = 0 ; d < 11 - c; d++)
    {
      if (dist[d][0] > dist[d+1][0]) /* For decreasing order use < */
      {
        swap       = dist[d][1];
        dist[d][1]   = dist[d+1][1];
        dist[d+1][1] = swap;
        
        swap_2       = dist[d][0];
        dist[d][0]   = dist[d+1][0];
        dist[d+1][0] = swap_2;

        swap_3       = dist[d][2];
        dist[d][2]   = dist[d+1][2];
        dist[d+1][2] = swap_3;
        
        swap_4       = dist[d][3];
        dist[d][3]   = dist[d+1][3];
        dist[d+1][3] = swap_4;
      
        swap_5       = dist[d][4];
        dist[d][4]   = dist[d+1][4];
        dist[d+1][4] = swap_5;
      
      }
    }
  }
}


float servo_angle(float x1, float y1, int x2, int y2)
{
  float param, result;
  if(y1 == 0)
  {
  param = (y2 - y1) / (x2 - x1);
  result = 90 - ( atan (param) * 180 / PI );
  return result;
  }
  else if(x1 == 0)
  {
  param = (x2- x1) / (y2 - y1) ;
  result = 90 - ( atan (param) * 180 / PI );
  return result;
  } 
  
}


void setup() 
{ 
  Serial.begin(9600);  
  
  // Servos initialize ----- x axis = 0 to 5 ------ y axis 6 to 9 
  for(int temp = 0; temp < 12; temp++ )
  {
    servo_control[temp].attach(temp+2);  
  }  

}
 
 
void loop() 
{
  
  for (int a = 0; a < 6; a++)
  {
    Serial.print("Person Number:");
    Serial.println(a);
    
    int count_laser = 0;
    int counta=0;
    int countb=0;
      
 
      int temp1 = 0, temp2 = 0;
      while(countb<=6)
      {
         if(laser_coord[temp1 = random(6)][2] == 0) 
      {
          Serial.println("Move Servo X Axis");
          Serial.println(temp1);
          laser_coord[temp1][2] = 1;  
          countb++;
          
          } 
          else
          { countb++;
            continue;
          }
          break;       
      }
        
      while(counta<=6) 
      {
          if(laser_coord[temp2 = random(6,12)][2] == 0)
          {
          Serial.println("Move Servo Y Axis");
          Serial.println(temp2);
          laser_coord[temp2][2] = 1;        
          counta++;
          
          } 
          else
          { counta++;
            continue;
          }
          break;
      }        
    
  
  
    

    
   //while(1);
  }
  
 // while(1);



 
  
   /*
   for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      laser_1_0.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      laser_1_0.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    }
   */ 
}

