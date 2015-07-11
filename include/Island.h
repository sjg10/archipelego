/*
 * Island.h
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#ifndef ISLAND_H_
#define ISLAND_H_
#include "Archipelego.h"

class Island
{
	Position pos;
	int weight;
	Team team;
	int score;
public:
	void subtract_score(int s);
	void double_score();
	Island(Position pos_sq, Team this_team,
		   int initial_weight, int initial_score): pos(pos_sq),
												   weight(initial_weight),
												   team(this_team),
												   score(initial_score) {};
	Island() : pos(Position()),
			   weight(0),
			   team(NEUTRAL),
			   score(0) {};
};


#endif /* ISLAND_H_ */
