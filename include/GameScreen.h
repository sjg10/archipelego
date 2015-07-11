/*
 * GameScreen.h
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
#include "Archipelego.h"
#include "Island.h"
#include "Squadron.h"

class GameScreen {
	int height;
	int width;
	int num_islands;
	int num_squadrons;
	Island* islands[MAX_ISLANDS];
	Squadron* squadrons[MAX_SQUADRONS];
	bool running;
	void increase_islands();
	void check_input(Island input_islands[][2], int player);
	void launch_squadrons(Island input_islands[][2], int player);
	void check_collisions();
	void check_landings();
	Team check_winning_team();
public:
	GameScreen(int x, int y, int rand_seed);
	bool run();
	virtual ~GameScreen();
};

#endif /* GAMESCREEN_H_ */
