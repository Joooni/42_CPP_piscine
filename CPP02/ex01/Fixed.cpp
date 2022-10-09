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

Fixed::Fixed(int const	param)
{
	std::cout << "Int constructor called\n";
	this->value = param << Fixed::fract_bits;
}

Fixed::Fixed(float const	param)
{
	std::cout << "Float constructor called\n";
	this->value = roundf(param * (1 << Fixed::fract_bits));
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

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::fract_bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> Fixed::fract_bits);
}

std::ostream &operator<<(std::ostream &outstream, Fixed const &value)
{
	outstream << value.toFloat();
	return (outstream);
}
