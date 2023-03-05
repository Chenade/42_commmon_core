#include "Point.hpp"

using namespace std;

float sign(Point const point, Point const a, Point const b)
{
	return (
		(point.getX().toFloat() - b.getX().toFloat()) *
		(a.getY().toFloat() - b.getY().toFloat()) - (a.getX().toFloat() - b.getX().toFloat()) *
		(point.getY().toFloat() - b.getY().toFloat()));
}

bool isOnLine(Point a, Point b, Point point)
{
	Fixed m = 0, n = 0;

	if (((Fixed) b.getX().toFloat() - a.getX().toFloat()) != 0)
		m =  ((Fixed) b.getY().toFloat() - a.getY().toFloat()) / ((Fixed) b.getX().toFloat() - a.getX().toFloat());
	if (((Fixed) point.getX().toFloat() - b.getX().toFloat()) != 0)
		n = ((Fixed) point.getY().toFloat() - b.getY().toFloat()) / ((Fixed) point.getX().toFloat() - b.getX().toFloat());
	if (m == n)
		return (true);
	else
		return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	if (a == point || b == point || c == point)
		return (false);

	if (isOnLine(a, b, point) || isOnLine(b, c, point) || isOnLine(c, a, point))
		return (false);

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}