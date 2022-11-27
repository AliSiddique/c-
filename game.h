#include "robot.h"
#include <map>

class game {
    std::map<std::string, robot> robots; // names for each known player
    public:
    game(){};
    int num_robots() const;
    void move(const std::string &name, int dir);
    int num_within(int n) const;
    int max_travelled() const;
    std::vector<std::string> robots_by_distance() const;

};