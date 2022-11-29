#ifndef ROBOT_H
#define ROBOT_H
//  robots movements class
class robot {
    int north_distance; // distance travelled north
    
    int south_distance; // distance travelled south
    
    int east_distance; // distance travelled east
    
    int west_distance; // distance travelled west
    
    int total_distance; // total distance travelled

    // starts the robot at the origin
    public:
        robot(); // default constructor for the robot
    
    
    void move_north(); // moves the robot one step north
    
    void move_south(); // moves the robot one step south
    
    void move_east(); // moves the robot one step east
   
    void move_west();  // moves the robot one step west

    // returns the total distance travelled by this robot since it was created
    int travelled() const;

    // returns the current distance north of the robot
    int north() const;

    // returns the current distance east of the robot
    int east() const;

};
// returns the distance of robot r from the origin according the Manhattan metric
int distance(const robot &r);
#endif