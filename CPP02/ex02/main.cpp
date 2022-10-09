#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "comparsion checking:" << std::endl;
	std::cout << "a < b (should be 0):	" << (a < b) << std::endl;
	std::cout << "b < c (should be 1):	" << (b < c) << std::endl;
	std::cout << "b > d (should be 0):	" << (b < d) << std::endl;
	std::cout << "a > b (should be 1):	" << (a > b) << std::endl;
	std::cout << "a <= b (should be 0):	" << (a <= b) << std::endl;
	std::cout << "b <= c (should be 1):	" << (b <= c) << std::endl;
	std::cout << "b >= a (should be 0):	" << (b >= a) << std::endl;
	std::cout << "b >= d (should be 1):	" << (b >= d) << std::endl;
	std::cout << "a == b (should be 0):	" << (a == b) << std::endl;
	std::cout << "b == d (should be 1):	" << (b == d) << std::endl;
	std::cout << "b != d (should be 0):	" << (b != d) << std::endl;
	std::cout << "a != b (should be 1):	" << (a != b) << std::endl;

	std::cout << "arithmetic checking:" << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "b * c: " << (b * c) << std::endl;
	std::cout << "c / b: " << (c / b) << std::endl;

	Fixed e;
	std::cout << "In- and decrementing test" << std::endl;
	std::cout << ""<< e << std::endl;
	std::cout << "pre increment:\t";
	std::cout << ++e << std::endl;
	std::cout << "\t\t"<< e << std::endl;
	std::cout <<  "post increment:\t";
	std::cout << e++ << std::endl;
	std::cout << "\t\t"<< e << std::endl;
	std::cout << "pre decrement:\t";
	std::cout << --e << std::endl;
	std::cout << "\t\t"<< e << std::endl;
	std::cout << "post decrement:\t";
	std::cout << e-- << std::endl;
	std::cout << "\t\t"<< e << std::endl;

	std::cout << "show smaller of a and e:\t" << Fixed::min( a, e ) << std::endl;
	std::cout << "show bigger of a and e:\t\t" << Fixed::max( a, e ) << std::endl;
	std::cout << "show smaller of b and c:\t" << Fixed::min( b, c ) << std::endl;
	std::cout << "show bigger of b and c:\t\t" << Fixed::max( b, c ) << std::endl;

	return (0);
}
