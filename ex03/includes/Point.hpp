#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include "iostream.h"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(); 	//default constructor
		Point(float const x, float const y); //parametrized constructor
		Point(Point const &other); //copy constructor
		Point &operator = (const Point &other); //copy assignment operator
	 ~Point();
}
#endif