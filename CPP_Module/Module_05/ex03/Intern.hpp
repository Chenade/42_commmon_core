# ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();

   		Intern& operator=(const Intern& intern);
		Form*	makeForm(std::string request, std::string target);
};

#endif