
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 145, 137 ), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : Form( src ), _target( src._target ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
    (void)rhs;
    return *this;
}

void    RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    if ( this->getSigned() == false )
        throw Form::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }
	int random_num = std::rand() % 100 + 1;

	if (random_num % 2)
    	std::cout << this->_target << " has been robotomized" << std::endl;
	else
    	std::cout << this->_target << " robotomy failed." << std::endl;
}