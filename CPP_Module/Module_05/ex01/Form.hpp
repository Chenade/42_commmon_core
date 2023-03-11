# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

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
		~Form();

   		Form& operator=(const Form& form);

		bool		getSigned() const;
		std::string	getName() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		void	beSigned(const Bureaucrat& bureaucrat);

	/* ---------------- Exception Classes ---------------- */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};

std::ostream&   operator<<(std::ostream& o, const Form& form);

#endif
