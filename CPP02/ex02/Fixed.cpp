#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{

}

Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
}

Fixed::Fixed(int const	param)
{
	this->value = param << Fixed::fract_bits;
}

Fixed::Fixed(float const	param)
{
 	this->value = roundf(param * (1 << Fixed::fract_bits));

}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator= (const Fixed &src)
{
	this->value = src.value;
	return (*this);
}

bool Fixed::operator> (const Fixed &cmp) const
{
	return (this->getRawBits() > cmp.getRawBits());
}

bool Fixed::operator< (const Fixed &cmp) const
{
	return (this->getRawBits() < cmp.getRawBits());
}

bool Fixed::operator>= (const Fixed &cmp) const
{
	return (this->getRawBits() >= cmp.getRawBits());
}

bool Fixed::operator<= (const Fixed &cmp) const
{
	return (this->getRawBits() <= cmp.getRawBits());
}

bool Fixed::operator== (const Fixed &cmp) const
{
	return (this->getRawBits() == cmp.getRawBits());
}

bool Fixed::operator!= (const Fixed &cmp) const
{
	return (this->getRawBits() != cmp.getRawBits());
}

Fixed Fixed::operator+ (const Fixed &src) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + src.getRawBits());
	return (result);
}

Fixed Fixed::operator- (const Fixed &src) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - src.getRawBits());
	return (result);
}

Fixed Fixed::operator* (const Fixed &src) const
{
	Fixed result(this->toFloat() * src.toFloat());
	return (result);
}

Fixed Fixed::operator/ (const Fixed &src) const
{
	Fixed result(this->toFloat() / src.toFloat());
	return (result);
}

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return (tmp);

}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return (tmp);

}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed& Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed& Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

std::ostream &operator<<(std::ostream &outstream, Fixed const &value)
{
	outstream << value.toFloat();
	return (outstream);
}
