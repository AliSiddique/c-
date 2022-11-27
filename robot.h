#pragma once
// record of robots movements
class robot{
    // distance travelled north
    int north_distance;
    // distance travelled south
    int south;
    // distance travelled east
    int east_distance;
    // distance travelled west
    int west;
    // total distance travelled
    int total_distance;
    // starts the robot at the origin
    public:
        robot() : north_distance(0), east_distance(0), south(0), west(0){};
    
    // move the robot one step north
    void move_north();
    // move the robot one step south
    void move_south();
    //move the robot one step east
    void move_east();
    // move the robot one step west
    void move_west();
    // return the total distance travelled by the robot since the start
    int travelled() const;
    // function for returning the current distance north of the robot
    int north() const;
    // function for returning the current distance east
    int east() const;

};
int distance(const robot &r);
