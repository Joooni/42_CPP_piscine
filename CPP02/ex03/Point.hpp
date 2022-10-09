#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>		// for std::roundf
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		~Point();
		Point(float x_init, float y_init);
		Point(const Point &point);
		Point	&operator= (Point &src);
		Fixed	getX() const;
		Fixed	getY() const;

};

std::ostream &operator<<(std::ostream &outstream, const Point &point);

#endif
