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
		Form(std::string name, std::string target, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		~Form();

		virtual void	swap(Form &other);

		std::string		getName() const;
		bool			getSignedStatus() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		std::string		getTarget() const;
		void			beSigned(Bureaucrat &bc);
		void			execute(const Bureaucrat &executor) const;
		virtual void	executeConcrete() const = 0;

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
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, Form &form);

#endif
