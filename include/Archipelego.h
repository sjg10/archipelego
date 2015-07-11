/*
 * Archipelego.h
 *
 *  Created on: 9 Jul 2015
 *      Author: sam
 */

#ifndef ARCHIPELEGO_H_
#define ARCHIPELEGO_H_

#include <cstdlib>
#include <iostream>
#include <ctime>

#define DEFAULT_HEIGHT 640
#define DEFAULT_WIDTH  480
#define MAX_ISLANDS    20
#define ISLAND_PARAMS  6
#define MAX_SQUADRONS  100
#define NUM_PLAYERS    2

#define TRUE        1
#define FALSE       (!TRUE)

enum Team
{
	RED,
	BLUE,
	NEUTRAL
};

class Position
{
	int x;
	int y;
	public:
		Position(int x_new, int y_new) : x(x_new), y(y_new) {};
		Position() : x(0), y(0) {};
		void set_pos(int x_new, int y_new) {x = x_new; y = y_new;};
		int get_x() {return x;};
		int get_y() {return y;};
		bool operator==(const Position &other) {return (x == other.x) &&
													   (y == other.y);};
};




#endif /* ARCHIPELEGO_H_ */
