
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <time.h>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		const std::string   _target;

		RobotomyRequestForm();

	public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		~RobotomyRequestForm();

		RobotomyRequestForm&  operator=( RobotomyRequestForm& rhs );

		void        execute( const Bureaucrat& executor ) const;
};

#endif