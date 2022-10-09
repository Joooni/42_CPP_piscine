#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "-*--*--*--*-\tTest 1\t\t\t-*--*--*--*-" << std::endl;
	{
		Bureaucrat Hermes;
		std::cout << "Bureaucrat " << Hermes.getName() << " with grade " << Hermes.getGrade() << " reporting for duty!" << std::endl;
	}
	std::cout << "-*--*--*--*-\tTest 2\t\t\t-*--*--*--*-" << std::endl;
	{
		Bureaucrat Hermes;
		Bureaucrat Morgan("Morgan Proctor", 19);
		Bureaucrat tmp;
		tmp = Morgan;
		std::cout << Hermes << " reporting for duty!" << std::endl;
		std::cout << Morgan << " reporting for duty!" << std::endl;
		Hermes.incrementGrade();
		std::cout << Morgan.getName() << " promotes Hermes to Grade " << Hermes.getGrade() << "!" << std::endl;
	}
	std::cout << "-*--*--*--*-\tTest 3\t\t\t-*--*--*--*-" << std::endl;
	try
	{
		Bureaucrat Hermes;
		Bureaucrat Boss("Number 1.0", 1);
		std::cout << Hermes << " reporting for duty!" << std::endl;
		std::cout << Boss << " reporting for duty!" << std::endl;
		std::cout << Boss.getName() << " tries to promote himself!" << std::endl;
		Boss.incrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << "-*--*--*--*-\tTest 3.2\t\t-*--*--*--*-" << std::endl;
	try
	{
		Bureaucrat Hermes;
		Bureaucrat Boss("Number 1.0", 0);
		std::cout << "Bureaucrat " << Hermes.getName() << " with grade " << Hermes.getGrade() << " reporting for duty!" << std::endl;
		std::cout << "Bureaucrat " << Boss.getName() << " with grade " << Boss.getGrade() << " reporting for duty!" << std::endl;
		std::cout << Boss.getName() << " tries to promote himself!" << std::endl;
		Boss.incrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << "-*--*--*--*-\tTest 3.3\t\t-*--*--*--*-" << std::endl;
	try
	{
		Bureaucrat Hermes;
		Bureaucrat Bob("Lowbob McLowBobface", 150);
		std::cout << Hermes << " reporting for duty!" << std::endl;
		std::cout << Bob << " reporting for duty!" << std::endl;
		std::cout << Hermes.getName() << " tries to demote " << Bob.getName() << "!" << std::endl;
		Bob.decrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
	std::cout << "-*--*--*--*-\tTest 4\t\t\t-*--*--*--*-" << std::endl;
	try
	{
		Bureaucrat Konrad("Konrad", 149);
		Bureaucrat Boss("Number 1.0", 1);
		std::cout << Konrad << " reporting for duty!" << std::endl;
		std::cout << Boss << " reporting for duty!" << std::endl;
		std::cout << Boss.getName() << " tries to demote Konrad!" << std::endl;
		Konrad.decrementGrade();
		std::cout << Konrad << " is sad he got demoted :(" << std::endl;
		std::cout << Boss.getName() << " tries to demote Konrad! Again!" << std::endl;
		Konrad.decrementGrade();
	}
	catch(std::exception &exception)
	{
		std::cout << "Exception caught! " << exception.what() << std::endl;
	}
}
