#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>		// for std::roundf

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(int const	param);
		Fixed(float const param);
		~Fixed();

		//assignment operator
		Fixed& operator= (const Fixed &src);
		//comparsion operators
		bool operator> (const Fixed &cmp) const;
		bool operator< (const Fixed &cmp) const;
		bool operator<= (const Fixed &cmp) const;
		bool operator>= (const Fixed &cmp) const;
		bool operator!= (const Fixed &cmp) const;
		bool operator== (const Fixed &cmp) const;
		//arithmetic operators
		Fixed operator+ (const Fixed &src) const;
		Fixed operator- (const Fixed &src) const;
		Fixed operator* (const Fixed &src) const;
		Fixed operator/ (const Fixed &src) const;
		//increment/decrement operator
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed &lhs, Fixed &rhs);
		static const Fixed&	min(const Fixed &lhs, const Fixed &rhs);
		static Fixed&		max(Fixed &lhs, Fixed &rhs);
		static const Fixed&	max(const Fixed &lhs, const Fixed &rhs);

	private:
		int					value;
		static const int	fract_bits = 8;
};

std::ostream &operator<<(std::ostream &outstream, Fixed const &value);

#endif
