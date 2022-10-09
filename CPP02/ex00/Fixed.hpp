#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator= (const Fixed &src);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	fract_bits = 8;
};

#endif
