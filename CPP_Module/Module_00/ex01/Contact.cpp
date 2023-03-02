/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 Contact.cpp										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ykuo <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/02/28 04:59:46 by ykuo			   #+#	  #+#			  */
/*	 Updated: 2023/02/28 09:20:29 by ykuo			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "Contact.hpp"

using namespace std;

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

string Contact::_getInput(string prompt) const {
    string input;
    while (true) {
        cout << prompt << flush;
        if (!getline(cin, input)) {
            if (cin.eof()) {
                cin.clear();
                input = "";
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input; please try again." << endl;
            }
        } else {
            if (!input.empty()) {
                break;
            } else {
                cout << "Invalid input; please try again." << endl;
            }
        }
    }
    return input;
}

void	Contact::init(void) {
	this->_firstName = this->_getInput("Please enter you first name: ");
	this->_lastName = this->_getInput("Please enter your last name: ");
	this->_nickname = this->_getInput("Please enter your nickname: ");
	this->_phoneNumber = this->_getInput("Please enter your phone number: ");
	this->_darkest_secert = this->_getInput("Please enter your darkest secret: ");
	cout << endl;
}


string Contact::_printLen(string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::setIndex(int i) {
	this->_index = i;
}

void	Contact::view(int index) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return ;
	cout << "|" << setw(10) << index << flush;
	cout << "|" << setw(10) << this->_printLen(this->_firstName) << flush;
	cout << "|" << setw(10) << this->_printLen(this->_lastName) << flush;
	cout << "|" << setw(10) << this->_printLen(this->_nickname) << flush;
	cout << "|" << endl;
}

void	Contact::display(int index) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return ;
	cout << endl;
	cout << "---->> CONTACT #" << index << " <<----" << endl;
	cout << "First Name:\t" << this->_firstName << endl;
	cout << "Last Name:\t" << this->_lastName << endl;
	cout << "Nickname:\t" << this->_nickname << endl;
	cout << std::endl;
}
