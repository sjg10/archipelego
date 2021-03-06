/*
 * Squadron.h
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#ifndef SQUADRON_H_
#define SQUADRON_H_
#include "Archipelego.h"
#include "Island.h"

class Squadron {
	int size;
	Position pos;
	Position trajectory;
	Team team;
	Island target;
public:
	Squadron(int size_sq, Position pos_sq,
			Position trajectory_sq, Team team_sq, Island target_sq) :
				 size(size_sq), pos(pos_sq),
				 trajectory(trajectory_sq), team(team_sq), target(target_sq) {};
	void update_position();
	Squadron() : size(0), pos(Position()),
			 trajectory(Position()), team(NEUTRAL), target(Island()) {};
};

#endif /* SQUADRON_H_ */
