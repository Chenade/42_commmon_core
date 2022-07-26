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

int check_valid(char **av, int index)
{
  int i;

  i = -1;
  while (av[index][++i])
  {
    if (!ft_isdigit(av[index][i]) && !(av[index][i] == '-' && i == 0))
      return (0);
  }
  if (av[index][0] == '-' && ft_atoi(av[index]) > 0)
    return (0);
  if (av[index][0] != '-' && ft_atoi(av[index]) < 0)
    return (0);
  i = 0;
  while (av[++i])
  {
    if (index != i && !ft_strcmp(av[index], av[i]))
      return (0);
  }
  return (1);
}

int get_order(char **av, int index)
{
  int num;
  int order;
  int i;

  num = ft_atoi(av[index]);
  order = 0;
  i = 0;
  while (av[++i])
  {
    if (ft_atoi(av[i]) < num)
      order += 1;
  }
  return (order);
}

int main(int argc, char **argv)
{
  int count;
  int valid;
  int *order;

  order = (int *) malloc((argc - 1) * sizeof(int));
  if(!order)
    return (ft_print_err("Error\n"), 1);
  ft_bzero(order, argc - 1);

  count = 0;
  while (++count < argc)
  {
    valid = check_valid(argv, count);
    order[count - 1] = get_order(argv, count);
    if (!valid)
      return (ft_print_err("Error\n"), 1);
  }

   for(int i = 0; i < argc - 1; i++)
      printf("%d, ", order[i]);


    //   while (valid && count < argc){
    //     ft_bzero(bin, INT_SIZE);
    //     valid = convert_to_binary(ft_atoi(argv[count]), bin);
    //     printf("\ninput: %s, valid: %d\n", argv[count], valid);
    //     // push('a', stack, &top, stackSize);

    //     printf("\nConverted binary: ");
    //     for(i=0; i<(int) INT_SIZE; i++)
    //         printf("%d", bin[i]);
    //     count += 1;
    // }

    // int stackSize = 4;
    // char stack[stackSize];
    // // A negative index shows that the stack is empty
    // int top = -1;
    
    // push('a', stack, &top, stackSize);
    // printf("Element on top: %c\n", stack[top]);

    // push('b',stack, &top, stackSize);
    // printf("Element on top: %c\n", stack[top]);

    // pop(stack, &top, stackSize);
    // printf("Element on top: %c\n", stack[top]);

    // pop(stack, &top, stackSize);
    // printf("Top: %d\n", top);

    // pop(stack, &top, stackSize);

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