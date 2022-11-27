#include "game.h"
#include "robot.h"
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int game::num_robots() const {
    return robots.size();
}

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
	if(robots.count(name) < 0){
		
		robots[name];
		move(name,dir);
	}

};

int game::num_within(int n)const {
	int num_wit = 0;
	for (const auto &p : robots) {
		double overall = p.second.travelled();
		if (overall <= n ) {
			++num_wit;
		}
	}
	return num_wit;
};

int game::max_travelled() const {
	double best_yet = 0;
	double distance = 0;
	for (const auto &p : robots) {
		double overall = p.second.travelled();
		if (overall > best_yet) {
			best_yet = overall;
			distance = p.second.travelled();
		}
	}
	return distance;
}
// bool compare_recent(const std::map<std::string, double> &x,
// 		const std::map<std::string, double> &y) {
// 	return x.second > y.second;
// }
// std::vector<std::string> game::robots_by_distance()const {
// 	std::vector<std::string, double>all;
// 	for (const auto &p : robots)
// 		all.push_back(vector<std::string, double>(p.first,
// 			p.second));

// 	std::sort(all.cbegin(), all.cend());

// 	std::vector<string> best;
// 	for (const auto &p : all)
// 		best.push_back(p.first);
// 	return best;
// }
// is the player a novice?
// bool travel(const pair<string, robot> &p) {

// 	return p.second.travelled();
// }

// the number of novice players
//  std::vector<std::string> game::robots_by_distance() const{
// 	sort(robots.cbegin(), robots.cend(), travel);
//     std::vector<std::string> names;
// 	for (const auto &p : names)
// 		robots.push_back(p.first);
// 	return names;
// };
