/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 05:50:20 by ykuo              #+#    #+#             */
/*   Updated: 2023/02/28 09:12:09 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>

using namespace std;
int main(void) {
    PhoneBook book;
    string input = "";

    book.welcome();
    while (true) {
        cout << "> " << flush;
        if (!getline(cin, input)) {
            if (cin.eof()) {
                break;
            }
        }
        if (input.compare("EXIT") == 0) {
            break;
        }
        if (input.compare("ADD") == 0) {
            book.addContact();
        } else if (input.compare("SEARCH") == 0) {
            book.printContact();
            book.searchContact();
        }
    }
    return 0;
}

