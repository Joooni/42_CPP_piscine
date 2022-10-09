#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
		this->_known_materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
		this->_known_materias[i] = NULL;
	*this = src;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
	{
		if (this->_known_materias[i] != NULL)
			delete this->_known_materias[i];
		this->_known_materias[i] = NULL;
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
	{
		if (this->_known_materias[i] != NULL)
			delete this->_known_materias[i];
		if (rhs._known_materias[i] != NULL)
			this->_known_materias[i] = rhs._known_materias[i]->clone();
		else
			this->_known_materias[i] = NULL;
	}
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *newMateria)
{
	if (this->_num_known_materias >= MateriaSource::_known_materias_size)
		std::cout << "This MateriaSource cannot learn any more materias" << std::endl;
	else
	{
		this->_known_materias[_num_known_materias] = newMateria;
		this->_num_known_materias++;
		std::cout << "Learned new " << newMateria->getType() << " Materia" << std::endl;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MateriaSource::_known_materias_size && this->_known_materias[i] != NULL; i++)
	{
		if (this->_known_materias[i]->getType() == type)
			return (this->_known_materias[i]->clone());
	}
	return (NULL);
}

AMateria	*MateriaSource::getKnownMateria(int idx) const
{
	return (this->_known_materias[idx]);
}
