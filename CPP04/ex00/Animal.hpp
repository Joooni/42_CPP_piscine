#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif


class	Animal
{
	public:
		Animal();
		Animal(const Animal &ct);
		Animal& operator=(const Animal &src);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &os, const Animal &animal);

#endif
