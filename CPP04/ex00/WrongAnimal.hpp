#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &ct);
		WrongAnimal &operator=(const WrongAnimal &src);
		virtual ~WrongAnimal();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &os, const WrongAnimal &WrongAnimal);

#endif
