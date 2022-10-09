#include "Point.hpp"

//math used: https://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	scalar_a;
	Fixed	scalar_b;
	Fixed	scalar_c;

	Fixed denom(((b.getY() - c.getY()) * (a.getX() - c.getX())) + ((c.getX() - b.getX()) * (a.getY() - c.getY())));
	scalar_a = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denom;
	scalar_b = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denom;
	scalar_c = Fixed(1) - scalar_a - scalar_b;

	return (Fixed(0) <= scalar_a && scalar_a <= Fixed(1) && Fixed(0) <= scalar_b && scalar_b <= Fixed(1) && Fixed(0) <= scalar_c && scalar_c <= Fixed(1));
}
