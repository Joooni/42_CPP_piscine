#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("Robotomy Request Form", target, 145, 137)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src)
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	RobotomyRequestForm(rhs).swap(*this);
	if (M_DEBUG == 1)
		std::cout << "Form " << this->getName() << " copy operated" << std::endl;
	return (*this);
}

/* void	RobotomyRequestForm::swap(RobotomyRequestForm &other)
{
	std::swap(this->_isSigned, other._isSigned);
} */

void	RobotomyRequestForm::executeConcrete() const
{
	srand(time(NULL));   // Initialization, should only be called once.
	std::cout << "*skrrbzzzzzz biuuuuuuuuu bzzzzzzzz*" << std::endl;
	int r = rand() % 2;
	if (r == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << "'s robotomy has failed!" << std::endl;
}