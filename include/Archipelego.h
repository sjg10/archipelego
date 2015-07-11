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
#include <stdexcept>

#define DEFAULT_HEIGHT 640
#define DEFAULT_WIDTH  480
#define MAX_ISLANDS    20
#define ISLAND_PARAMS  6
#define MAX_SQUADRONS  100
#define NUM_PLAYERS    2

#ifdef DEBUG
#define DEBUG_STATEMENT(statement) (statement)
#else
#define DEBUG_STATEMENT(statement)
#endif

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
		friend std::ostream & operator<<(std::ostream & Str, Position const & v);
};

inline std::ostream & operator<<(std::ostream & Str, Position const & v)
{
	Str << "(" << v.x << " " << v.y << ")";
	return Str;
}


#endif /* ARCHIPELEGO_H_ */
