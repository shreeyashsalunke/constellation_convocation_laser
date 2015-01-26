#include <Servo.h> 
#include <Math.h> 
 

int pos = 0;    // variable to store the servo position 

// Coords from Kinnet
int coordinates_x_y [5][2] = {{600,100},{400,200},{200,300},{100,500},{500,500}}; // Assumed some random point for humans

// Predefined coords
int laser_coord[12][2] = {{100,0},{200,0},{300,0},{400,0},{500,0},{600,0},{0,100},{0,200},{0,300},{0,400},{0,500},{0,600}};


//Distance from laser
float dist[12][5] = {{0,0,0,100,0}, {1,0,0,200,0}, {2,0,0,300,0}, {3,0,0,400,0}, {4,0,0,500,0}, {5,0,0,600,0}, {6,0,0,0,100}, {7,0,0,0,200}, {8,0,0,0,300}, {9,0,0,0,400}, {10,0,0,0,500}, {11,0,0,0,500}};
float angle = 0;

//float dist_sorted[12][5];

// Servos (x, y)
Servo servo_control[12];  

double calculate_distance (double x1, double y1, double x2 , double y2)
{
  double distance;
  double distance_x = x1 - x2;
  double distance_y = y1- y2; 
  
  distance = sqrt( (distance_x * distance_x) + (distance_y * distance_y));
  
  return distance;
}

void remove_laser(float dist[12][5])
{ 
  for(int i=0 ; i<12; i++)
  {
    if(dist[i][3]==1)
       dist[i][0] = dist[i+1][0];
       dist[i][1] = dist[i+1][1];
       dist[i][2] = dist[i+1][2];
       dist[i][3] = dist[i+1][4];
       dist[i][4] = dist[i+1][5];
         
  }
}

void sort(float dist[12][5])
{
  int c, d;
  float swap, swap_2, swap_3, swap_4, swap_5;
  
  for (c = 0 ; c < 11 ; c++)
  { 
    if( dist[c][2]==0)
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
  result = atan (param) * 180 / PI;
  if(result < 0)
  {
    result = result + 180;
  }
  
  Serial.println("Real Angle needed");
  Serial.println(result);
  
  result = map(result, 0, 180, 10, 120);
 
  Serial.println("Angle Jugad");
  Serial.println(result);
  
  return result;
  }
  else if(x1 == 0)
  {
  param = (x2- x1) / (y2 - y1) ;
  result = atan (param) * 180 / PI;
/*  if(result < 0)
  {
    result = result + 180;    // --------------------------------------------Check for -ve angles left to check
  } */
  
  Serial.println("Real Angle needed");
  Serial.println(result);
  
  result = map(result, 0, 180, 10, 120);
 
  Serial.println("Angle Jugad");
  Serial.println(result);
  
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
  
  for (int a = 0; a < 5; a++)
  {
    Serial.println("Before Sorting");
    for(int b = 0; b < 12; b++)
    {
      dist[b][1] = calculate_distance(laser_coord[b][0], laser_coord[b][1], coordinates_x_y[a][0], coordinates_x_y[a][1]);
      
      Serial.println(dist[b][0]); 
      Serial.println(dist[b][1]); 
    }
    
   sort(dist); 
    
    Serial.println("After Sorting");    
    for(int b = 0; b < 12; b++)
    {
      Serial.println(dist[b][0]); 
      Serial.println(dist[b][1]); 
      Serial.println(dist[b][2]); 
      //Serial.println(dist[b][3]); 
      //Serial.println(dist[b][4]); 

    }
   /* Serial.println("Move Laser");
    Serial.println(dist[0][0]);
    Serial.println("At an angle");
    Serial.println(servo_angle(dist[0][3], dist[0][4], coordinates_x_y[a][0], coordinates_x_y[a][1]));
    dist[0][2]=1;
    
   /* Serial.println("Move Laser");
    Serial.println(sizeof(dist)/sizeof(dist[0][0]));
    Serial.println(dist[(sizeof(dist)/2)][0]);
    Serial.println("At an angle");
    Serial.println(servo_angle(dist[(sizeof(dist)/2)][3], dist[(sizeof(dist)/2)][4], coordinates_x_y[a][0], coordinates_x_y[a][1]));
    dist[(sizeof(dist)/2)][2]=1;*/
    
    /*
    Serial.println("Move Laser");
    Serial.println(sizeof(dist)/(sizeof(float)*5));
    Serial.println(dist[((sizeof(dist)/(sizeof(float)*5))-1)][0]);
    
    Serial.println("At an angle");
    Serial.println(servo_angle(dist[((sizeof(dist)/(sizeof(float)*5))-1)][3], dist[((sizeof(dist)/(sizeof(float)*5))-1)][4], coordinates_x_y[a][0], coordinates_x_y[a][1]));
    dist[((sizeof(dist)/(sizeof(float)*5))-1)][2]=1;
    
    
    */
    
    
    
   int count_laser = 0;
      
    for(int c = 0; c <6; c++)
    {
      
        if(dist[c][2]==0)
        {
          // go to some function
          angle = servo_angle(dist[c][3], dist[c][4], coordinates_x_y[a][0], coordinates_x_y[a][1]);
          
          servo_control[(int)dist[c][0]].write(angle);
          delay(50);
          
          
          Serial.println("servo selected");
          Serial.println(dist[c][0]);  
      
          Serial.println("servo angle");
          Serial.println(angle);      
              
          
          
          Serial.println("Move Laser");
          //Serial.println(dist[c][0]);  
          //Serial.println(angle);  
          //Serial.println(dist[c][3]);
          //Serial.println(dist[c][4]);      
          //Serial.println(coordinates_x_y[a][0]);
          //Serial.println(coordinates_x_y[a][1]);
          
         count_laser++;  
          dist[c][2] = 1;
          break;
        }   
        
      
      
    }
    
    for(int c = 6; c < 12; c++)
    {
      
        if(dist[c][2]==0)
        {
          // go to some function
          angle = servo_angle(dist[c][3], dist[c][4], coordinates_x_y[a][0], coordinates_x_y[a][1]);
          
          Serial.println("Move Laser");
          //Serial.println(dist[c][0]);  
          //Serial.println(angle);  
          
          servo_control[(int)dist[c][0]].write(angle);
          delay(50);
          
          Serial.println("servo selected");
          Serial.println(dist[c][0]);  
      
          Serial.println("servo angle");
          Serial.println(angle);      
              
          
          //Serial.println(dist[c][3]);
          //Serial.println(dist[c][4]);      
          //Serial.println(coordinates_x_y[a][0]);
          //Serial.println(coordinates_x_y[a][1]);
          
         count_laser++;  
          dist[c][2] = 1;
          break;
        }   
        
      
      
    }
    
  
/* Serial.println("Removing laser");  
    remove_laser(dist);
    for(int i=0;i<12;i++)
      Serial.println(dist[i][0]);
    sort_2_back (dist);*/

//count=count+3;    
   // while(1);
  }
  
  while(1);



 
  
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
