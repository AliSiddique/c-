#ifndef GAME_H
#define GAME_H
#include "robot.h"
#include <vector>
#include <map>

class game {
    
   std::map<std::string, robot> robots;  // map holding the names and the robot
public:
    game(); // game constructor
    
    int num_robots() const; // returns the total number of robots in the game
    
    void move(const std::string &name, int dir); // move the named robot one step in the specified direction
    
    int num_within(int n) const; // the total number of robots within n steps of the origin
   
    int max_travelled() const;  // the distance of the robot who has travlled the furthest
    
    std::vector<std::string> robots_by_distance() const; //  the names of the robots in ascending order from the origin

};
#endif