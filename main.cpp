#include "robot.h"
#include "game.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    robot r;
    r.move_north();
    r.move_east();
    r.move_south();
    r.move_east();
    r.move_north();
    cout << "Position: " << r.north() << " N, " << r.east() << " E\n";
    cout << "Distance: " << distance(r) << '\n';
    cout << "Travelled: " << r.travelled() << '\n';
    game  g;
    cout << "Count before: " << g.num_robots() << '\n';
    g.move("Robbie", 1); // east
    g.move("Marvin", 2); // south
    g.move("Robbie", 3); // west
     g.move("ali", 1); // west
    g.move("ali", 3); // west



  cout << "Count after: " << g.num_robots() << '\n';
  cout << "Furtherest travelled: " << g.max_travelled() << '\n';
  cout << "Within 0 steps: " << g.num_within(0) << '\n';
  cout << "Within 1 step: " << g.num_within(1) << '\n';
  for (const auto &name : g.robots_by_distance())
    cout << name << '\n';

return 0;
};