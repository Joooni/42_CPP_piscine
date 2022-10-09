#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 1 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat			Hermes;
		ShrubberyRequestForm Document;

		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		Document.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}

}
