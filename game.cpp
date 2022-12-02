#include "game.h"
#include "robot.h"
#include <algorithm>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
game::game(){};
// returns the number of robots in a game
int game::num_robots() const {
    return robots.size(); // returns the map size
};

// moves the named robot one step in the specified direction
void game::move(const std::string &name, int dir){
	if(dir == 0){
    robots[name].move_north();

	}
	if(dir == 1){
    robots[name].move_east();

	}
	if(dir == 2){
    robots[name].move_south();

	}
	if(dir == 3){
    robots[name].move_west();

	}
			// if robots name is not in the game
	if(robots.count(name) < 1){
		// add robot to the game
		robots[name];
		// move the named robot in the specified direction
		move(name,dir);
	}


};

//returns the number of robots that are no more than n steps from the origin.
int game::num_within(int n)const {
	int num_wit = 0; // variable to count number of robots with n steps of origin

	// loop through map to find robots
	// for (const auto &p : robots) {
	// 	// calculates distance from the origin
	// 	// if distance is within n steps
	// 	if (distance(p.second) <= n ) {
	// 		// increment num_with by 1
	// 		num_wit++;
	// 	}
	// }
	for(auto itr = robots.begin(); itr != robots.end();++itr){
		if(distance((*itr).second) <= n){
			num_wit++;
		}
	}
	// return the number of robots within the distance
	return num_wit;
};

// returns the furthest distance a robot has travelled
int game::max_travelled() const {

	int furthest_travelled = 0; // variable holding the furthesr distance travelled
	// loop through the robots map
	for (const auto &p : robots) {
		// the distance of that the robot has travelled
		int distance = p.second.travelled();
		// if the robots distance is greater than an another robots distance
		if (distance > furthest_travelled) {
			// change furthest travelled to the robots distance travelled
			furthest_travelled = p.second.travelled();
		}
	}
	// return the furthest distance
	return furthest_travelled;
};

bool compare_recent(const pair<string, double> &x,
		const pair<string, double> &y) {
	return x.second < y.second;
};
// compare the robots distance from the origin
vector<string> game::robots_by_distance() const {
	// copy all robots and their names into a vector
	vector<pair<string, double>> all;
	for (const auto &p : robots)
		all.push_back(pair<string, double>(p.first,
			distance(p.second)));

	// sort in decreasing order of distance
	sort(all.begin(), all.end(), compare_recent);

	// copy strings to a new vector for return
	vector<string> order;
	for (const auto &p : all)
		order.push_back(p.first);
	return order;
};
