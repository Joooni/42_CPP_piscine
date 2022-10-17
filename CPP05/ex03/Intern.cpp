#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
	if (M_DEBUG == 1)
		std::cout << "Default Intern constructed" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
	if (M_DEBUG == 1)
		std::cout << "Intern copy constructed" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
	if (M_DEBUG == 1)
		std::cout << "Intern assignment operated" << std::endl;
}

Intern::~Intern()
{
	if (M_DEBUG == 1)
		std::cout << "Intern destructed" << std::endl;
}

Form *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	t_formList forms[] =
	{
		{"shrubbery creation", new ShrubberyCreationForm(formTarget)},
		{"robotomy request", new RobotomyRequestForm(formTarget)},
		{"presidential pardon", new PresidentialPardonForm(formTarget)},
		{"", NULL}
	};

	Form *res = NULL;
	for (int i = 0; forms[i].formType != NULL; i++)
	{
		if (forms[i].formName == formName)
			res = forms[i].formType;
		else
			delete forms[i].formType;
	}
	if (res == NULL)
		std::cerr << "Intern could not create form " << formName << std::endl;
	else
		std::cout << "Intern created " << formName << "!" << std::endl;
	return (res);
}

std::ostream &operator<<(std::ostream &os, Intern const &obj)
{
	(void)obj;
	os << "Intern" << std::endl;
	return (os);
}
