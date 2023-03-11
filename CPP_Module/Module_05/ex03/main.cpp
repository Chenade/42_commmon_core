
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    {
        std::cout << "\n-------------------  Intern --------------------" << std::endl;
        Bureaucrat bureaucrat("ash", 2);
        Intern  intern;
        Form*   formbyIntern;

        formbyIntern = intern.makeForm("robotomy request", "Bender");
        if (formbyIntern) bureaucrat.signForm(*formbyIntern);
        if (formbyIntern) bureaucrat.executeForm(*formbyIntern);
        delete formbyIntern;
        std::cout << "\n----------------  Intern (failed) -----------------" << std::endl;
        formbyIntern = intern.makeForm("robotomsy request", "Bender2");
        if (formbyIntern) bureaucrat.signForm(*formbyIntern);
        delete formbyIntern;
    }

    try {
        Bureaucrat bureaucrat("ash", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}