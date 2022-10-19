#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	private:
		static const int	nbr_ideas = 100;
		std::string	ideas[Brain::nbr_ideas];

	public:
		Brain();
		Brain(const Brain &rhs);
		Brain &operator=(const Brain &rhs);
		~Brain();

		std::string getIdea(int i);
		void		setIdea(std::string idea, int i);

};

#endif
