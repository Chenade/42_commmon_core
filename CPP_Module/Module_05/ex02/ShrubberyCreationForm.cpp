
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137 ), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : Form( src ), _target( src._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
    (void)rhs;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
    if ( this->getSigned() == false )
        throw Form::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }

    std::ofstream file((this->_target + "_shrubbery").c_str());

    file << "                                                     ." << std::endl;
    file << "                                          .         ;  " << std::endl;
    file << "             .              .              ;%     ;;   " << std::endl;
    file << "               ,           ,                :;%  %;   " << std::endl;
    file << "                :         ;                   :;%;'     .,   " << std::endl;
    file << "       ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                  `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "                    `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "                      `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                        ;@%. :@%%  %@@%;       " << std::endl;
    file << "                          %@bd%%%bd%%:;     " << std::endl;
    file << "                            #@%%%%%:;;" << std::endl;
    file << "                            %@@%%%::;" << std::endl;
    file << "                            %@@@%(o);  . '         " << std::endl;
    file << "                            %@@@o%;:(.,'         " << std::endl;
    file << "                        `.. %@@@o%::;         " << std::endl;
    file << "                           `)@@@o%::;         " << std::endl;
    file << "                            %@@(o)::;        " << std::endl;
    file << "                           .%@@@@%::;         " << std::endl;
    file << "                           ;%@@@@%::;.          " << std::endl;
    file << "                          ;%@@@@%%:;;;. " << std::endl;
    file << "                      ...;%@@@@@%%:;;;;,.." << std::endl;

    file.close();
}