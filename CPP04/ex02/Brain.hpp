#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class	Brain
{
	private:
		static const int	nbr_ideas = 100;

	public:
		Brain();
		Brain(const Brain &rhs);
		Brain &operator=(const Brain &rhs);
		~Brain();

		std::string getIdea(int i);
		void		setIdea(std::string idea, int i);

		std::string	ideas[Brain::nbr_ideas];
};

#endif
