#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# ifndef M_DEBUG
#  define M_DEBUG	0
# endif

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		~Form();

		void			swap(Form &other);

		std::string		getName() const;
		bool			getSignedStatus() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			beSigned(Bureaucrat &bc);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, Form &form);

#endif
