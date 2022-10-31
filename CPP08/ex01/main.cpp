#include "Span.hpp"

#include <list>
#include <iostream>
#include <string>

#define DELIM		std::cout << std::string(50, '~') << std::endl;

int main(void)
{
	DELIM;
	std::cout << COLOR_BLUE << "Baseline Tests" << END << std::endl;
	DELIM;
	std::cout << "Creating spA with size 0!" << std::endl;
	Span spA;
	try
	{
		std::cout << "trying to add 5 to spA: " << std::endl;
		spA.addNumber(5);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	DELIM;
	try
	{
		std::cout << "Shortest span of SpA: ";
		std::cout << spA.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span of SpA: ";
		std::cout << spA.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	DELIM;
	Span spB(5);
	try
	{
		std::cout << "trying to add 150 to spB: ";
		spB.addNumber(150);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 415 to spB: ";
		spB.addNumber(415);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 234 to spB: ";
		spB.addNumber(234);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add -5 to spB: ";
		spB.addNumber(-5);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 64 to spB: ";
		spB.addNumber(64);
		std::cout << "Success!" << std::endl;
		std::cout << "trying to add 9001 to spB: ";
		spB.addNumber(9001);
		std::cout << "Success!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	DELIM;
	std::cout << "Longest span of SpB: " << spB.longestSpan() << std::endl;
	std::cout << "Shortest span of SpB: " << spB.shortestSpan() << std::endl;
	DELIM;
	std::cout << COLOR_BLUE  << "Copy and assignment tests" << END << std::endl;
	DELIM;
	std::cout << COLOR_CYAN << "Copy construct spCopy and copy assign those to spCpAs" << END << std::endl;
	Span	spCopy(spB);
	Span	spCpAs;
	spCpAs = spCopy;
	try
	{
	std::cout << "Longest span of SpCopy: " << spCopy.longestSpan() << std::endl;
	std::cout << "Shortest span of SpCopy: " << spCopy.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
	std::cout << "Longest span of SpCpAs: " << spCpAs.longestSpan() << std::endl;
	std::cout << "Shortest span of SpCpAs: " << spCpAs.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << COLOR_CYAN << "Changing values in spCopy and spCpAs to check for deep copies" << END << std::endl;
	std::cout << COLOR_CYAN << "spCopy: replace 234 with 42069" << END << std::endl;
	std::cout << COLOR_CYAN << "spCpAs: replace -5 with -1005" << END << std::endl;
	spCopy.replace(234, 42069);
	spCpAs.replace(-5, -1005);
	try
	{
	std::cout << "Longest span of SpB: " << spB.longestSpan() << std::endl;
	std::cout << "Shortest span of SpB: " << spB.shortestSpan() << std::endl;
	std::cout << "Longest span of SpCopy: " << spCopy.longestSpan() << std::endl;
	std::cout << "Shortest span of SpCopy: " << spCopy.shortestSpan() << std::endl;
	std::cout << "Longest span of SpCpAs: " << spCpAs.longestSpan() << std::endl;
	std::cout << "Shortest span of SpCpAs: " << spCpAs.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	DELIM;
	std::cout << COLOR_BLUE  << "BIIIIG test" << END << std::endl;
	srand(time(NULL));
	Span spE(250000);
	for (int i = 0; i < 250000; i++)
		spE.addNumber(rand() * ((7 * i) % 135176));
	try
	{
		std::cout << "Longest span of SpE: " << spE.longestSpan() << std::endl;
		std::cout << "Shortest span of SpE: " << spE.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	DELIM;
	std::cout << COLOR_BLUE  << "BIIIIG test 2 with fillSpan" << END << std::endl;
	Span spF(250000);
	std::vector<int> vec_spF;
	for (int i = 0; i < 250000; i++)
		vec_spF.push_back(i);
	try
	{
		spF.fillSpan(vec_spF.begin(), vec_spF.end());
		std::cout << "Shortest span of spF: " << spF.shortestSpan() << std::endl;
		std::cout << "Longest span of spF: " << spF.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
