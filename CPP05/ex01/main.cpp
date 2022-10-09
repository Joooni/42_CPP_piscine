#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 1 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat	Hermes;
		Form		Document;

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
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 2 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat	Hermes;
		Form		Document("Cake Requisition Form BR-0W-N132", 140, 150);
		Form		Copy(Document);

		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
		Copy.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << std::endl << "\t\t(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Test 3 ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	try
	{
		Bureaucrat	Hermes;
		Form		Document("Beer Consumption Form B4Y-R3U7H3R", 50, 150);
		Form		Copy;

		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
		Copy = Document;
		Document.beSigned(Hermes);
		std::cout << Hermes << std::endl;
		std::cout << Document << std::endl;
		std::cout << Copy << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
}
