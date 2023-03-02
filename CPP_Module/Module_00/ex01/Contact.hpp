/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:57:07 by ykuo              #+#    #+#             */
/*   Updated: 2023/02/28 08:12:25 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
class Contact
{
private:
	string _firstName;
	string _lastName;
	string _nickname;
	string _phoneNumber;
	string _darkest_secert;
	int         _index;

	string _printLen(string str) const;
	string _getInput(string str) const;

public:
	Contact();
	~Contact();
	void    init(void);
	void    view(int index) const;
	void    display(int index) const;
	void    setIndex(int i);
};

#endif
