#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

# ifndef M_DEBUG
#  define M_DEBUG   0
# endif

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &rhs);
		~Intern();

		Form *makeForm(const std::string &formName, const std::string &formTarget);

	private:
		typedef struct s_formList
		{
			std::string	formName;
			Form		*formType;
		}	t_formList;
};

std::ostream &operator<<(std::ostream &os, Intern const &obj);

#endif
