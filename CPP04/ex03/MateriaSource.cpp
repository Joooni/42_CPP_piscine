#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _num_known_materias(0)
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
		this->_known_materias[i] = NULL;
	if (M_DEBUG)
		std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
	{
		if (src._known_materias[i])
			this->_known_materias[i] = src._known_materias[i]->clone();
		else
			this->_known_materias[i] = NULL;
	}
	if (M_DEBUG)
		std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
	{
		if (this->_known_materias[i])
			delete this->_known_materias[i];
	}
	if (M_DEBUG)
		std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < MateriaSource::_known_materias_size; i++)
	{
		if (this->_known_materias[i] != NULL)
			delete this->_known_materias[i];
		if (rhs._known_materias[i])
			this->_known_materias[i] = rhs._known_materias[i]->clone();
		else
			this->_known_materias[i] = NULL;
	}
	if (M_DEBUG)
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *newMateria)
{
	if (this->_num_known_materias >= MateriaSource::_known_materias_size)
	{
		std::cout << "This MateriaSource cannot learn any more materias" << std::endl;
		delete (newMateria);
	}
	else
	{
		this->_known_materias[_num_known_materias] = newMateria->clone();
		this->_num_known_materias++;
		std::cout << "Learned new " << newMateria->getType() << " Materia at slot " << this->_num_known_materias << std::endl;
	}

}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i = 0;

	while (i < MateriaSource::_known_materias_size && this->_known_materias[i] && this->_known_materias[i]->getType() == type)
		i++;
	if (i < MateriaSource::_known_materias_size && this->_known_materias[i])
		return (this->_known_materias[i]->clone());
	else
		return (NULL);
}

AMateria	*MateriaSource::getKnownMateria(int idx) const
{
	return (this->_known_materias[idx]);
}
