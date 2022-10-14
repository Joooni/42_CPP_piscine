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
        Intern &operator=(const Instern &rhs);
        ~Intern();

        makeForm(std::string formName, std::string formTarget);
};

#endif