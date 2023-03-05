#include "Point.hpp"

using namespace std;

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

bool Point::operator==(const Point& rhs) const
{
	bool com_x = ((Fixed) this->getX() == rhs.getX());
	bool com_y = ((Fixed) this->getY() == rhs.getY());
	return (com_x && com_y);
}
