#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath> // for std::roundf

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(int const	param);
		Fixed(float const param);
		Fixed& operator= (const Fixed &src);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value;
		static const int	fract_bits = 8;
};

std::ostream &operator<<(std::ostream &outstream, Fixed const &value);

#endif
