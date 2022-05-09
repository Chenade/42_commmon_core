/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:34:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/09 14:39:21 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 
int main()
{
    int a, b, c;
 
    printf("Enter value of a in decimal format:");
    scanf("%i", &a);
    printf("%%d -> %d\n", a);
    printf("%%i -> %i\n", a);
    printf("%%x -> %x\n", a);
    printf("%%X -> %X\n", a);
    //printf("%%i -> %i\n", a);
    //printf("%%i -> %i\n", a);

    printf("Enter value of b in octal format: ");
    scanf("%i", &b);
    printf("%%d -> %d\n", b);
    printf("%%i -> %i\n", b);
 
    printf("Enter value of c in hexadecimal format: ");
    scanf("%i", &c);
    printf("%%d -> %d\n", c);
    printf("%%i -> %i\n", c);
 
	printf("\n%%"); 
    return 0;
}
