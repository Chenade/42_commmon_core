/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 04:40:52 by ykuo              #+#    #+#             */
/*   Updated: 2023/02/28 04:45:52 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
int	main(int argc, char **argv) {
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++)
				cout << (char) toupper(argv[i][j]);
			if (i < argc - 1)
				cout << ' ';
		}
	}
	cout << endl;
	return (0);
}
