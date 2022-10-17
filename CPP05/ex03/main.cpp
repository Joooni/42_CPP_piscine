#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

int main(void)
{
	Intern		deskguy;
	Bureaucrat	Beholder("Beholder Monster", 3);
	Form		*form;

	form = deskguy.makeForm("this should not work", "random");
	if (form)
		delete form;
	form = deskguy.makeForm("shrubbery creation", "shrub.txt");
	if (form)
		delete form;
	form = deskguy.makeForm("robotomy request", "Bender");
	if (form)
		delete form;
	form = deskguy.makeForm("presidential pardon", "Zap Brannigan");
	form->beSigned(Beholder);
	form->execute(Beholder);
	if (form)
		delete form;
}
