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

#include "Point.hpp"

/*

*/

using namespace std;

int main ( void ) {
    if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ) == true )
        cout << "Point is in the triangle" << endl;
    else
        cout << "Point is not in the triangle" << endl;

    if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15) ) == true )
        cout << "Point is in the triangle" << endl;
    else
        cout << "Point is not in the triangle" << endl;
    return 0;
}