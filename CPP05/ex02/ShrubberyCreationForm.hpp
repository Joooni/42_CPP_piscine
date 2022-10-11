#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

//		void			swap(ShrubberyCreationForm &other);
		virtual void	executeConcrete() const;
};

#endif
