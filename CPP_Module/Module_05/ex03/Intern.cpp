# include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& intern)
{
    *this = intern;
}

Intern::~Intern() {}


Intern&   Intern::operator=( const Intern& intern )
{
    (void) intern;
    return (*this);
}

Form*	Intern::makeForm(std::string request, std::string target)
{
	Form*    forms[] = {
        new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
	};
    
	std::string requests_lst[] = {
		"shrubbery request",
		"robotomy request",
		"president request"
	};

	Form* return_form = NULL;
	
    for (int i = 0; i < 3; i++)
	{
        if (request == requests_lst[i]) {
            std::cout << "Intern creates " << target << std::endl;
            return_form = forms[i];
        }
		else
			delete (forms[i]);
    }
	if (!return_form)
		std::cout << "Intern cannot create " << target << " form, request: " << request << std::endl;
	return (return_form);
}