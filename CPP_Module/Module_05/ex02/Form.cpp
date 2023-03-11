#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(0)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& form) : _name(form.getName()), _gradeToSign(form.getGradeToSign()), _gradeToExec(form.getGradeToExecute())
{
}

Form::~Form()
{
}

Form&   Form::operator=( const Form& form )
{
    if (this != &form)
        _isSigned = form.getSigned();
    return *this;
}

std::string Form::getName() const
{
    return (_name);
}

bool   Form::getSigned() const
{
    return (_isSigned);
}

int   Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int   Form::getGradeToExecute() const
{
    return (_gradeToExec);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream&   operator<<(std::ostream& o, const Form& form)
{
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << form.getName() << std::endl
      << "Grade to sign: " << form.getGradeToSign() << std::endl
      << "Grade to execute: " << form.getGradeToExecute();
    return o;
}