#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Hermes Conroy"), _grade(34)
{
	if (M_DEBUG == 1)
		std::cout << "Default Bureaucrat constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (M_DEBUG == 1)
		std::cout << "Bureaucrat with name "<< this->_name << " and grade " << this->_grade << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name (src._name), _grade(src._grade)
{
	if (M_DEBUG == 1)
		std::cout << "Bureaucrat copy constructed" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	Bureaucrat(rhs).swap(*this);
	if (M_DEBUG == 1)
		std::cout << "Bureaucrat copy operated" << std::endl;
	return (*this);
}

void	Bureaucrat::swap(Bureaucrat &other)
{
	std::swap(this->_grade, other._grade);
}

Bureaucrat::~Bureaucrat()
{
	if (M_DEBUG == 1)
		std::cout << "Bureaucrat " << this->_name << " deconstructed" << std::endl;
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ಠ_ಠ Grade too low ಠ_ಠ");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ಠ_ಠ Grade too high ಠ_ಠ");
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &bc)
{
	os << "Bureaucrat "  << bc.getName() << " with Grade " << bc.getGrade();
	return (os);
}
