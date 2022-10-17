#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form()
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form("Presidential Pardon Form", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src)
{

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	PresidentialPardonForm(rhs).swap(*this);
	if (M_DEBUG == 1)
		std::cout << "Form " << this->getName() << " copy operated" << std::endl;
	return (*this);
}

/* void	PresidentialPardonForm::swap(PresidentialPardonForm &other)
{
	std::swap(this->_isSigned, other._isSigned);
} */

void	PresidentialPardonForm::executeConcrete() const
{
	std::cout << this->getTarget() << " has been pardoned by the great Zaphod Beeblebrox!" << std::endl;
}