/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:05:14 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/15 09:25:13 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "./general.h"

# define STR_ERROR "Error\n"

# define STR_OK "OK\n"
# define STR_KO "KO\n"

# define STR_RA "ra\n"
# define STR_RB "rb\n"
# define STR_RR "rr\n"

# define STR_RRA "rra\n"
# define STR_RRB "rrb\n"
# define STR_RRR "rrr\n"

# define STR_PA "pa\n"
# define STR_PB "pb\n"

# define STR_SA "sa\n"
# define STR_SB "sb\n"
# define STR_SS "ss\n"

int	str_to_cmd(char *str, t_stack **stack_a, t_stack **stack_b);
int	run_command(t_stack **stack_a, t_stack **stack_b);

#endif
