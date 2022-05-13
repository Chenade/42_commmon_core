/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:33:45 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/13 14:13:46 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	ans;

	ans = 0;
	if (!s)
		return (ans);
	while (s[ans])
		ans += 1;
	return (ans);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return (s1);
	if (cut_line(s2) > 0)
		ret = malloc(sizeof(char) * (ft_strlen(s1) + cut_line(s2) + 1));
	else
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	while (s1 && s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2[j] != '\n')
		ret[i++] = s2[j++];
	if (s2[j] == '\n')
		ret[i++] = s2[j];
	ret[i] = 0;
	free(s1);
	return (ret);
}

int	cut_line(char *line)
{
	int	i;

	i = -1;
	while (line && line[++i])
	{
		if (line[i] == 10)
			return (i + 1);
	}
	return (0);
}

void	clear_buffer(char *buffer)
{
	int	i;
	int	pos;

	i = 0;
	pos = cut_line(buffer);
	while (buffer[pos + i] && pos)
	{
		buffer[i] = buffer[pos + i];
		i += 1;
	}
	buffer[i] = '\0';
}
