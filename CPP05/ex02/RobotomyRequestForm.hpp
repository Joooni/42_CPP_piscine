#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <time.h>
# include <stdlib.h>

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm(const std::string target);

		void			swap(RobotomyRequestForm &other)
		virtual void	executeConcrete(const Bureaucrat &executor) const;
};

#endif
