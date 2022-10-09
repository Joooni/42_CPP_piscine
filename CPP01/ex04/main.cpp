#include "sed.hpp"

int	main( int argc, char *argv[])
{
	SedButWorse test;
	if (argc != 4)
	{
		std::cerr << "Wrong input, please give as arguments: Filename StringToReplace ReplacerString\n";
		return (1);
	}
	if (!(test.ReadInputFile(argv[1])))
	{
		std::cerr << "Error reading from file!\n";
		return (1);
	};
	test.ReplaceStrings(argv[2], argv[3]);
}
