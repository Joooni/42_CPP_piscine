#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x_init, const float y_init): x(x_init), y(y_init)
{
}

Point::Point(const Point &point): x(point.getX()), y(point.getY())
{
}

Point::~Point()
{
}

Point &Point::operator=(Point &src)
{
	return (src);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}

std::ostream &operator<<(std::ostream &outstream, const Point &point)
{
	outstream << "(" << point.getX() << "/" << point.getY() << ")";
	return (outstream);
}
