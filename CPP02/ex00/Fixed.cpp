#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called\n";
}

Fixed & Fixed::operator= (const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->value = src.value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}
