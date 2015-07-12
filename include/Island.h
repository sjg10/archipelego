/*
 * Island.h
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#ifndef ISLAND_H_
#define ISLAND_H_
#include "Archipelego.h"

#define MAX_WEIGHT

class Island
{
	Position pos;
	int weight;
	Team team;
	int score;
	int score_remainder;
public:
	void subtract_score(int s);
	void double_score();
	Island(Position pos_sq, Team this_team,
		   int initial_weight, int initial_score): pos(pos_sq),
												   weight(initial_weight),
												   team(this_team),
												   score(initial_score),
												   score_remainder(0) {};
	Island() : pos(Position()),
			   weight(0),
			   team(NEUTRAL),
			   score(0),
			   score_remainder(0) {};
	void increment_score();
	bool score_update_threshold();
	friend std::ostream & operator<<(std::ostream & Str, Island const & v);
};

inline std::ostream & operator<<(std::ostream & Str, Island const & v)
{
	Str << "( ";
	Str << "Pos: " << v.pos << " ";
	Str << "Weight: " << v.weight << " ";
	Str << "Team: ";
	switch(v.team)
	{
	case RED:
		Str << "RED";
		break;
	case BLUE:
		Str << "BLUE";
		break;
	case NEUTRAL:
		Str << "NEUTRAL";
		break;
	default:
		std::domain_error("Invalid team name for island.");
		break;
	}
	Str << " ";
	Str << "Weight: " << v.score << ")";
	return Str;
}


#endif /* ISLAND_H_ */
