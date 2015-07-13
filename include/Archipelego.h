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
#include <ctgmath>

#define DEFAULT_HEIGHT 640
#define DEFAULT_WIDTH  480
#define MAX_ISLANDS    20
#define ISLAND_PARAMS  6
#define MAX_SQUADRONS  100
#define NUM_PLAYERS    2

#define PI 3.14159265
enum Quadrant
{
	UPPER_RIGHT,
	UPPER_LEFT,
	LOWER_LEFT,
	LOWER_RIGHT
};

// The order of Quadrant enum is important for the following:
#define ANGLE_TO_QUADRANT(angle) ((Quadrant) (angle / (PI / 2)))

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

// TODO: Theres a lot of Position here. Extract to new file?
class Position
{
	int x;
	int y;
	public:
		Position(int x_new, int y_new) : x(x_new), y(y_new) {};
		Position() : x(0), y(0) {};
		void set_pos(int x_new, int y_new) {x = x_new; y = y_new;};
		int get_x() const {return x;};
		int get_y() const {return y;};
		bool operator==(const Position &other) const {return (x == other.x) &&
													   (y == other.y);};
		int distance(const Position &other) const;
		bool collision(const Position &other, int own_diameter, int other_diameter) const;
		friend std::ostream & operator<<(std::ostream & Str, Position const & v);
};

//TODO: test.
inline int Position::distance(const Position &other) const
{
	int sqr_distance = ((x - other.get_x()) * (x - other.get_x()) +
			  	  	  	(y - other.get_y()) * (y - other.get_y()));
	return std::sqrt(sqr_distance);
}

//TODO: test.
//TODO Is inline right?
//TODO; are you consistent in x/y mathematical order vs. gaming order?
// Check for intersection of circles in ZZ^2
inline bool Position::collision(const Position &other, int own_diameter, int other_diameter) const
{
	Position temp;
	Quadrant quadrant;
	double angle = 0;
	int x_offset, y_offset;
	double dbl_x_offset, dbl_y_offset;
	// TODO: pick efficient CIRCLE_POINTS based on WIDTH/HEIGHT
	// We spin around the integer points just inside the circumference aroun
	// other and see if they are within the diameter of this.
	#define CIRCLE_POINTS 360
	for(int theta = 0; theta < CIRCLE_POINTS; theta++)
	{
		angle    = 2*PI / theta;
		quadrant = ANGLE_TO_QUADRANT(angle);
		dbl_x_offset = other_diameter * sin(angle);
		dbl_y_offset = other_diameter * cos(angle);
		switch(quadrant)
		{
		case UPPER_LEFT:
			x_offset = ceil(dbl_x_offset);
			y_offset = floor(dbl_y_offset);
			break;
		case UPPER_RIGHT:
			x_offset = floor(dbl_x_offset);
			y_offset = floor(dbl_y_offset);
			break;
		case LOWER_LEFT:
			x_offset = ceil(dbl_x_offset);
			y_offset = ceil(dbl_y_offset);
			break;
		case LOWER_RIGHT:
			x_offset = floor(dbl_x_offset);
			y_offset = ceil(dbl_y_offset);
			break;
		default:
			std::domain_error("Invalid quadrant: bad angle.");
			break;
		}
		temp = Position(x + x_offset,y + y_offset);
		if(distance(temp) < own_diameter)
		{
			return true;
		}
	}
	return false;
}

inline std::ostream & operator<<(std::ostream & Str, Position const & v)
{
	Str << "(" << v.x << " " << v.y << ")";
	return Str;
}


#endif /* ARCHIPELEGO_H_ */
