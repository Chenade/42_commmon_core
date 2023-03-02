/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:57:07 by ykuo              #+#    #+#             */
/*   Updated: 2023/02/28 08:22:10 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
class PhoneBook
{
private:
	Contact		_contacts[8];
	int			_readInput(void) const;

public:
	PhoneBook();
	~PhoneBook();
	void    addContact(void);
	void	searchContact(void) const;
	void	printContact(void) const;
	void    welcome(void) const;
};

#endif
