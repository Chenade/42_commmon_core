
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		const std::string   _target;

		PresidentialPardonForm();

	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& src );
		~PresidentialPardonForm();

		PresidentialPardonForm&  operator=( PresidentialPardonForm& rhs );

		void        execute( const Bureaucrat& executor ) const;
};

#endif