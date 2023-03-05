# ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		// Constructors/Destructor
		Point(void);
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point(void);

		// std operator
		Point& operator=(const Point& rhs);
		bool operator==(const Point& rhs) const ;

		// Function
		Fixed const getX(void) const;
		Fixed const getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif