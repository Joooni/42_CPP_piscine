#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdlib>

int	pseudoHandler(std::string pseudo)
{
	int	i = 0;
	std::string pseudoArray[8] = {"-inf", "inf", "+inf", "nan", "-inff", "inff", "+inff", "nanf"};

	while (i < 8)
	{
		if (pseudoArray[i] == pseudo)
			break ;
		i++;
	}
	if (i < 8)
	{
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		if (i < 4)
		{
			std::cout << "float:\t" << pseudoArray[i + 4] << std::endl;
			std::cout << "double:\t" << pseudo << std::endl;
		}
		else
		{
			std::cout << "float:\t" << pseudo << std::endl;
			std::cout << "double:\t" << pseudoArray[i - 4] << std::endl;
		}
		return (1);
	}
	return (0);
}

void	printChar(double nbr)
{
	std::cout << "char:\t";
	if (nbr < 0 || nbr > 255)
		std::cout << "impossible" << std::endl;
	else if (nbr < 32 || nbr > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;
}

void	printInt(double nbr)
{
	std::cout << "in:\t";
	if (nbr > INT_MAX || nbr < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;
}

void	printFloat(double nbr)
{
	std::cout << "float:\t" << static_cast<float>(nbr);
	if (!fmod(nbr, 1))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	printDouble(double nbr)
{
	std::cout << "double:\t" << static_cast<double>(nbr);
	if (!fmod(nbr, 1))
		std::cout << ".0";
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments, should only be one" << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	if (pseudoHandler(input))
		return (0);

	double to_double;
	if (input.size() > 1 || isdigit(input[0]))
	{
		char *endPtr;
		to_double = strtod(argv[1], &endPtr);
		if (*endPtr != 'f' && *endPtr)
		{
			std::cout << "Number contains characters, please give correct input" << std::endl;
			return (1);
		}
	}
	else
		to_double = static_cast<double>(input[0]);
	printChar(to_double);
	printInt(to_double);
	printFloat(to_double);
	printDouble(to_double);
	return (0);
}
