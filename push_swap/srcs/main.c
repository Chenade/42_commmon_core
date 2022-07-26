/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo & cmenasse<marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:05:31 by ykuo              #+#    #+#             */
/*   Updated: 2022/06/14 17:54:56 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // int check_args(int argc, char **argv) {
// //     int valid = 1;
// //     if (argc != 3) {
// // 		ft_printf("\x1b[31mError: \x1b[0mBad number of arguments. Usage: ./push_swap <nb_rows> <nb_columns>\n");
// // 		valid = 0;
// // 	}else{
// //         int i = ft_atoi(argv[1]);
// //         int j = ft_atoi(argv[2]);
// //         if (i < MIN_ROW) {
// //             ft_printf("\x1b[31mError: \x1b[0mBad number of arguments. Usage: The mininum value for row is %d.\n", MIN_ROW);
// //             valid = 0;
// //         }
// //         if (j < MIN_COL) {
// //             ft_printf("\x1b[31mError: \x1b[0mBad number of arguments. Usage: The mininum value for column is %d.\n", MIN_COL);
// //             valid = 0;
// //         }
// //     }
// //     return (valid);
// // }

// void    convert_to_binary(int num, int *bin)
// {
//     int index;

//     index = INT_SIZE - 1;
//     while(index >= 0)
//     {
//         bin[index] = num & 1;
//         index--;
//         num >>= 1;
//     }
// }

// int main(int argc, char **argv)
// {
//     int i;
//     int count;
//     int bin[INT_SIZE];

//     count = 1;
//     while (count < argc){
//         ft_bzero(bin, INT_SIZE);
//         convert_to_binary(ft_atoi(argv[count]), bin);

//         printf("\nConverted binary: ");
//         for(i=0; i<(int) INT_SIZE; i++)
//             printf("%d", bin[i]);
//         count += 1;
//     }
//     return 0;
// }

void push(char element, char stack[], int *top, int stackSize){
 if(*top == -1){
  stack[stackSize - 1] = element;
  *top = stackSize - 1;
 }
 else if(*top == 0){
  printf("The stack is already full. \n");
 }
 else{
  stack[(*top) - 1] = element;
  (*top)--;
 }
}

void pop(char stack[], int *top, int stackSize){
 if(*top == -1){
   printf("The stack is empty. \n");
 }
 else{
  printf("===Element popped: %c \n", stack[(*top)]);
  // If the element popped was the last element in the stack
  // then set top to -1 to show that the stack is empty
  if((*top) == stackSize - 1){
    (*top) = -1;
  }
  else{
    (*top)++;
  }
 }
}

int main() {
  int stackSize = 4;
  char stack[stackSize];
  // A negative index shows that the stack is empty
  int top = -1;
  
  push('a', stack, &top, stackSize);
  printf("Element on top: %c\n", stack[top]);

  push('b',stack, &top, stackSize);
  printf("Element on top: %c\n", stack[top]);

  pop(stack, &top, stackSize);
  printf("Element on top: %c\n", stack[top]);

  pop(stack, &top, stackSize);
  printf("Top: %d\n", top);

  pop(stack, &top, stackSize);
  return 0;
}


// int main(){
//     int size = a.size();
//     int max_num = size - 1; // the biggest number in a is stack_size - 1
//     int max_bits = 0; // how many bits for max_num 
//     while ((max_num >> max_bits) != 0) ++max_bits;
//     for (int i = 0 ; i < max_bits ; ++i) // repeat for max_bits times
//     {
//         for(int j = 0 ; j < size ; ++j)
//         {
//             int num = a.top(); // top number of A
//             if ((num >> i)&1 == 1) ra(); 
//             // if the (i + 1)-th bit is 1, leave in stack a
//             else pb();
//             // otherwise push to stack b
//         }
//         // put into boxes done
//         while (!b.empty()) pa(); // while stack b is not empty, do pa
        
//         // connect numbers done
//     }
// }