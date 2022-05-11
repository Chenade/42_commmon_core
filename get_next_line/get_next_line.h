/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:51:15 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/11 22:30:55 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_lINE_H
# define GET_NEXT_lINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_vi(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
