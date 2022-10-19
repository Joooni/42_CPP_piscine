#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < Brain::nbr_ideas; i++)
		this->setIdea("some random jingle", i);
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	*this = rhs;
	std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < Brain::nbr_ideas; i++)
		this->ideas[i] = rhs.ideas[i];
	std::cout << "Copy assignment operator of Brain called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(int i)
{
	if (i < 0 || i > 99)
		return ("invalid idea index, idiot");
	else
		return (this->ideas[i]);
}

void		Brain::setIdea(std::string idea, int i)
{
	if (i < 0 || i > 99)
	{
		std::cout << "invalid idea index, idiot" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
}
