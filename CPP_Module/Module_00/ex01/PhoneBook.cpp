/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:59:46 by ykuo              #+#    #+#             */
/*   Updated: 2023/02/28 09:15:09 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using namespace std;

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook()
{
}

int     PhoneBook::_readInput() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        cout << "Please enter the contact index: " << flush;
        cin >> input;
        if (cin.good() && (input >= 0 && input <= 8)) {
            valid = true;
        } else {
            cin.clear();
            cout << "Invalid index; please re-enter." << endl;
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::addContact(void){
	static int i;
	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i += 1;
}

void	PhoneBook::searchContact(void) const {
	int i = this->_readInput();
	this->_contacts[i % 8].display(i);
}

void	PhoneBook::printContact(void) const {
	for (int i = 0; i < 8; i ++)
		this->_contacts[i].view(i);
}

void    PhoneBook::welcome(void) const {
	cout << "Welcome to the PhoneBook!" << endl;
}

