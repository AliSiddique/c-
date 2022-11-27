#include "game.h"
#include "robot.h"
#include <algorithm>
#include <map>
#include <cstdlib>
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
		double overall = abs(p.second.north() - 0) + (p.second.east() - 0);
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
};

bool compare_recent(const pair<string, double> &x,
		const pair<string, double> &y) {
	return x.second > y.second;
};
vector<string> game::robots_by_distance() const {
	// copy all players and recent averages into a vector
	vector<pair<string, double>> all;
	for (const auto &p : robots)
		all.push_back(pair<string, double>(p.first,
			p.second.travelled()));

	// sort in decreasing order of recent average
	sort(all.begin(), all.end(), compare_recent);

	// copy strings to a new vector for return
	vector<string> best;
	for (const auto &p : all)
		best.push_back(p.first);
	return best;
};