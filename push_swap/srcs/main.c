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

void  print_both_stack(t_stack **stack_a, t_stack **stack_b)
{
  ft_printf("========================\n");
	ft_printf("stack a: ");
	ft_stack_print(stack_a);
	ft_printf("stack b: ");
	ft_stack_print(stack_b);
  ft_printf("========================\n");
}

int  push_swap(t_stack **stack_a, t_stack **stack_b)
{
	print_both_stack(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_both_stack(stack_a, stack_b);
  sb(1, stack_b);
	print_both_stack(stack_a, stack_b);

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
  return (0);
}

int  init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
  int count;
  int valid;

  count = argc;
  while (--count > 0)
  {
    valid = check_valid(argv, count);
    if (!valid)
      return (ft_print_err("Error\n", stack_a, stack_b), 1);
    ft_stack_push(stack_a, ft_stack_new(get_order(argv, count)));
  }
  return (0);
}

int main(int argc, char **argv)
{
  int status;
  t_stack  **stack_a;
  t_stack  **stack_b;

 if (argc == 1)
    return (0);
  stack_a = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
  stack_b = (t_stack **) malloc((argc - 1) * sizeof(t_stack *));
  if(!stack_a || ! stack_b)
    return (ft_print_err("Error\n", stack_a, stack_b), 1);
  *stack_a = NULL;
  *stack_b = NULL;
  status = init_stack(argc, argv, stack_a, stack_b);
  if (!status)
    status = push_swap(stack_a, stack_b);
  ft_stack_clear (stack_a);
  ft_stack_clear (stack_b);
  return (status);
}