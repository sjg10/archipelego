/*
 * Island.cpp
 *
 *  Created on: 12 Jul 2015
 *      Author: sam
 */

#include "Island.h"

void Island::increment_score()
{
	score_remainder++;
	if(score_update_threshold())
	{
		score++;
		score_remainder = 0;
	}
}

bool Island::score_update_threshold()
{
	//TODO: invent appropriate scoring threshold.
	return true;
}

