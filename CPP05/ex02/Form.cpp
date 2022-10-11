#include "Form.hpp"

Form::Form() : _name("Passierschein A-38"), _target("Asterix und Obelix"), _isSigned(false), _gradeToSign(38), _gradeToExecute(38)
{
	if (M_DEBUG == 1)
		std::cout << "Standard Form constructed" << std::endl;
}

Form::Form(std::string name, std::string target, int gradeToSign, int gradeToExecute):  _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw(Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw(Form::GradeTooLowException());
	if (M_DEBUG == 1)
		std::cout << this << " with parameters constructed" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _target(src._target), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	if (M_DEBUG == 1)
		std::cout << this << " copy constructed" << std::endl;
}

Form	&Form::operator=(const Form &rhs)
{
	this->_isSigned = rhs._isSigned;
	return (*this);
}

void	Form::swap(Form &other)
{
	std::swap(this->_isSigned, other._isSigned);
}

Form::~Form()
{
	if (M_DEBUG == 1)
		std::cout << "Form " << this->_name << " deconstructed" << std::endl;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getSignedStatus() const
{
	return (this->_isSigned);
}

int			Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

std::string		Form::getTarget() const
{
	return (this->_target);
}

void		Form::beSigned(Bureaucrat &bc)
{
	if (this->getGradeToSign() < bc.getGrade())
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

void	Form::execute(const Bureaucrat &executor) const
{
	if (this->_gradeToExecute < executor.getGrade())
		throw Form::GradeTooLowException();
	if (this->_isSigned != true)
		throw Form::FormNotSignedException();
	executeConcrete();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("ಠ_ಠ Grade too low ಠ_ಠ");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("ಠ_ಠ Grade too high ಠ_ಠ");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("ಠ_ಠ Form has not been signed ಠ_ಠ");
}

std::ostream	&operator<<(std::ostream &os, Form &form)
{
	os	<< "Form " << form.getName()
		<< " with signature here (" << (form.getSignedStatus() ? "X)" : " )")
		<< " needs Grade " << form.getGradeToSign() << " to sign"
		<< " and Grade " << form.getGradeToExecute() << " to execute";
	return (os);
}
