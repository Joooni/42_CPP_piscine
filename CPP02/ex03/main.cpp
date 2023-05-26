#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(2, 2);
	Point b(6, 4);
	Point c(4, 7);
	Point d(4, 5);
	Point e(5, 2);
	Point test(0, 0);
	std::cout << test << a << std::endl;
	test = a;
	test = b;
	test = c;
	test = d;
	test = e;
	std::cout << test << a << std::endl;
	std::cout << "Triangle vertices:\na: " << a << "\nb: " << b << "\nc: " << c << std::endl;
	std::cout << "Is point d at: " << d << " inside? (should be 1) " << bsp(a, b, c, d) << std::endl;
	std::cout << "Is point e at: " << e << " inside? (should be 0) " << bsp(a, b, c, e) << std::endl;
	std::cout << "Is point test at: " << test << " inside triangle of " << a << b << c << " ? (should be 0) " << bsp(a, b, c, test) << std::endl;
	std::cout << "Is point test at: " << test << " inside triangle of " << test << b << c << " ? (should be 1) " << bsp(test, b, c, test) << std::endl;
	return (0);
}
