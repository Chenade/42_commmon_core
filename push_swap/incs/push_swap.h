#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# include "../libft/libft.h"

# define INT_SIZE sizeof(int) * 8 /* Size of int in bits */
# define INT_MAX 2147483647

typedef struct {
	int	rows;  	//game rows
    int cols;	//game cols
	int idx;
	int idx_p;
    int	move;	//move number		
	int	turn;	//player who made the move (user or AI)	
	char *board;	//board	
}	t_game;

int	ft_strcmp(char *s1, char *s2);
void ft_print_err(char *msg);
char *convert_to_binary(int num);
void ft_push(char element, char stack[], int *top, int stackSize);
void ft_pop(char stack[], int *top, int stackSize);


#endif