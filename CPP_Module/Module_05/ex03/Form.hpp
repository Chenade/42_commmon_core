# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(const std::string& name, int gradeToSign);
    	Form(const std::string& name, int gradeToSign, int gradeToExecute);
    	Form(const Form& src);
		virtual ~Form();

   		Form& operator=(const Form& form);

		bool		getSigned() const;
		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0;


	/* ---------------- Exception Classes ---------------- */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
	class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form is unsigned"; }
    };
};

std::ostream&   operator<<(std::ostream& o, const Form& form);

#endif
