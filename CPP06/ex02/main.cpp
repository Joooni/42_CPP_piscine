#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	srand(time(NULL));   // Initialization, should only be called once.
	int rando = rand() % 3;
	switch (rando)
	{
		case 0: std::cout << "Generating A!" << std::endl; return (new A());
		case 1: std::cout << "Generating B!" << std::endl; return (new B());
		case 2: std::cout << "Generating C!" << std::endl; return (new C());
		default: return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Identifying by pointers... base class is A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Identifying by pointers... base class is B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Identifying by pointers... base class is C" << std::endl;
}

void	identify(Base &p)
{
	Base ref;

	try
	{
		ref = dynamic_cast<A &>(p);
		std::cout << "Identifying by reference... base class is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ref = dynamic_cast<B &>(p);
		std::cout << "Identifying by reference... base class is B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		ref = dynamic_cast<C &>(p);
		std::cout << "Identifying by reference... base class is C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	Base *Base;
	std::cout << std::string(25, '-') << "Testcase" << std::string(25, '-') << std::endl;
	Base = generate();
	identify(Base);
	identify(*Base);
	delete Base;
	return (0);

}