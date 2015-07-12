/*
 * GameScreen.cpp
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#include "GameScreen.h"

GameScreen::GameScreen(int x, int y, int rand_seed)
{
	std::srand(rand_seed);
	height = x;
	width = y;
	running = false;
	num_squadrons = 0;
	num_islands = (std::rand() % MAX_ISLANDS) + 1;
	for(int i = 0; i < num_islands; i++)
	{
		//TODO: randoms to sensible values.
		islands[i] = new Island(Position(std::rand() % height, std::rand() % width),
							    (Team) (std::rand() % (NUM_PLAYERS + 1)),
							    std::rand() , std::rand() % MAX_WEIGHT + 1);
		DEBUG_STATEMENT(std::cout << "New island: " << *islands[i] << std::endl);
	}
}

bool GameScreen::run()
{
	running = true;
	Island input_islands[NUM_PLAYERS][MAX_ISLANDS][2];
	//draw_initial(); TODO:GUI
	Team winning_team = NEUTRAL;
	while(running)
	{
		increase_islands();
		for(int player =0; player <= NUM_PLAYERS; player++)
		{
			check_input(input_islands[player], player);
			launch_squadrons(input_islands[player], player);
		}
		check_collisions();
		check_landings();
		winning_team = check_winning_team();
		if(winning_team != NEUTRAL)
		{
			running = false;
		}
		//redraw() TODO:GUI
	}
	return true;
}

GameScreen::~GameScreen() {
	// TODO Auto-generated destructor stub
}


void GameScreen::increase_islands()
{
	for(int i = 0; i < num_islands; i++)
		{
			islands[i]->increment_score();
		}
}

//TODO:
void GameScreen::check_input(Island input_islands[][2], int player){return;}
void GameScreen::launch_squadrons(Island input_islands[][2], int player){return;}
void GameScreen::check_collisions(){return;}
void GameScreen::check_landings(){return;}
Team GameScreen::check_winning_team(){return NEUTRAL;}

