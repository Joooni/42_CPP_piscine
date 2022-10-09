#include "sed.hpp"

SedButWorse::SedButWorse()
{

}

SedButWorse::~SedButWorse()
{

}

bool	SedButWorse::ReadInputFile(std::string filename)
{
	if (this->InputFileStream.is_open())
		this->InputFileStream.close();
	this->InputFileStream.open(filename.c_str(), std::ifstream::in);
	this->filename = filename;
	return (true);
}

bool	SedButWorse::ReplaceStrings(std::string str1, std::string str2)
{
	if (str1 == "" || str2 == "")
	{
		std::cerr << "Strings can't be empty!\n";
		return (false);
	}
	char			c;
	std::string		content;
	c = InputFileStream.get();
	while (InputFileStream.good())
	{
		content.append(1, c);
		c = InputFileStream.get();
	}
	if (str1 != str2)
	{
		size_t	new_pos = 0;
		while (content.find(str1, new_pos) != std::string::npos)
			{
				size_t	pos = content.find(str1, new_pos);
				content.erase(pos, str1.size());
				content.insert(pos, str2);
				new_pos = pos + str2.size();
			}
	}
	this->OutputToFile(content);
	return (true);
}

void	SedButWorse::OutputToFile(std::string content)
{
	std::ofstream	OutputFileStream;
	std::string		OutputFileName = this->filename;

	OutputFileName.append(".replace");
	OutputFileStream.open(OutputFileName.c_str());
	OutputFileStream << content;
}
