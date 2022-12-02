#include "robot.h"
#include <cstdlib>
#include <iostream>

// sets up the robot at the origin
robot::robot() : north_distance(0), east_distance(0), south_distance(0), west_distance(0){};

// moves the robot one step north and adds to the total distance
void robot::move_north(){
   north_distance += 1;
   total_distance += 1;
};

// move the robot one step east and adds to the total distance
void robot::move_east(){
    east_distance += 1;
    total_distance += 1;

};

// move the robot one step to the south and adds to the total distance
void robot::move_south(){
   south_distance += 1;
   total_distance += 1;

};

// move the robot one step west and adds to the total distance
void robot::move_west(){
   west_distance += 1;
   total_distance += 1;

};

// return the distance north of the robot
int robot::north() const {
   // if south distance is greater or equal to the north distance subtract both from each other
   // if(south_distance > north_distance || south_distance == north_distance){
   //    int north = north_distance - south_distance;
   //    return north;
   // }
   // if south distance is not greater than north return the north distance
  int north = north_distance - south_distance;
      return north;
};

// return the distance east of the robot
int robot::east() const {
      // if west distance is greater or equal to the east distance subtract both from each other
  
   // if west distance is not greater than east return the north distance
  int eas = east_distance - west_distance;
      return eas;
};

// return the total distance the robot has travelled
int robot::travelled() const {
   return total_distance;
};

// calculates the manhatten matric from the origin
int distance(const robot &r){
  return abs(r.north()) + abs(r.east());
}