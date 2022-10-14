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
		Bureaucrat					Hermes;
		ShrubberyCreationForm		Document;
		ShrubberyCreationForm		ShrubDoc("Kleingarten 1");

		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		Document.beSigned(Hermes);
		ShrubDoc.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		Document.execute(Hermes);
		ShrubDoc.execute(Hermes);
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 2 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat	Hermes;
		RobotomyRequestForm		Document("Cake Requisition Form BR-0W-N132");
		RobotomyRequestForm		Copy(Document);

		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
		Copy.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
		Copy.execute(Hermes);
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 3 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat					Hermes;
		PresidentialPardonForm		PPForm("Beer Consumption Form B4Y-R3U7H3R");
		PresidentialPardonForm		Copy;

		std::cout << Hermes << std::endl;
		std::cout << PPForm << std::endl;
		std::cout << Copy << std::endl;
		Copy = PPForm;
		PPForm.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << PPForm << std::endl;
		std::cout << Copy << std::endl;
		PPForm.execute(Hermes);
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
}
