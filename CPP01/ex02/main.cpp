# include <iostream>
# include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::string(60, '#') << std::endl;
	std::cout << "Original string address:\t" << &string << std::endl;
	std::cout << "stringPTR address:\t\t" << &stringPTR << std::endl;
	std::cout << "stringREF address:\t\t" << &stringREF << std::endl;
	std::cout << std::string(60, '#') << std::endl;
	std::cout << "Original string:\t\t" << string << std::endl;
	std::cout << "String by pointer:\t\t" << *stringPTR << std::endl;
	std::cout << "String by reference:\t\t" << stringREF << std::endl;
	std::cout << std::string(60, '#') << std::endl;
}
