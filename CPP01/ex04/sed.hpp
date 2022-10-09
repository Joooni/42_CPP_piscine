#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

class SedButWorse {

	public:
	SedButWorse();
	~SedButWorse();
	bool	ReadInputFile(std::string filename);
	bool	ReplaceStrings(std::string str1, std::string str2);
	void	OutputToFile(std::string content);

	private:
	std::string string1;
	std::string string2;
	std::string filename;
	std::ifstream InputFileStream;


};

#endif
