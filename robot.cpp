#include "robot.h"
#include <cstdlib>
#include <iostream>
 // moving the robot one step north
void robot::move_north(){
   north_distance += 1;
   total_distance += 1;
};
// move the robot one step east
void robot::move_east(){
    east_distance += 1;
    total_distance += 1;

};
// move the robot one step to the south
void robot::move_south(){
   south += 1;
      total_distance += 1;

};
// move the robot one step west
void robot::move_west(){
   west += 1;
      total_distance += 1;

};
// return the distance north of the robot
int robot::north() const {
   if(south > north_distance || south == north_distance){
      int nor = north_distance - south;
      return nor;
   }
   return north_distance;
};
// return the distance east of the robot
int robot::east() const {
   if(west > east_distance || west == east_distance){
      int eas = east_distance - west;
      return eas;
   }
   return east_distance;
};
// rerurn the total distance travelled by the robot
int robot::travelled() const {
   
   return total_distance;

};
// return the distance of the robot to the origin
int distance(const robot &r){
   
  return abs(r.north() - 0) + (r.east() - 0);
};