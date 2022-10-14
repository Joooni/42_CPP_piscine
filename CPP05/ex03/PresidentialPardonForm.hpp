#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		
//		void			swap(PresidentialPardonForm &other);
		virtual void	executeConcrete() const;
};

#endif
