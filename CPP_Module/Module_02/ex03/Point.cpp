#include "Point.hpp"

// Constructor
Point::Point(void)
	: _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const float x, const float y)
	: _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point& srcs) : _x(srcs._x), _y(srcs._y)
{
}


// Decontructor
Point::~Point(void)
{
}

Point& Point::operator=(const Point& rhs)
{
	(void)rhs;
	// cout << "Assignment of const variables impossible, values will stay the same as in the default constructor." << endl;
	return *this;
}

Fixed const Point::getX(void) const
{
	return (this->_x);
}

Fixed const Point::getY(void) const
{
	return (this->_y);
}

float sign(Point const point, Point const a, Point const b)
{
	return (
		(point.getX().toFloat() - b.getX().toFloat()) *
		(a.getY().toFloat() - b.getY().toFloat()) - (a.getX().toFloat() - b.getX().toFloat()) *
		(point.getY().toFloat() - b.getY().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}