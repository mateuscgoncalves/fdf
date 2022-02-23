/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:23:28 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/22 16:52:07 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_getbuffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_nchr(buffer);
	if (j == 0)
	{
		buffer[0] = '\0';
		return ;
	}
	while (buffer[j])
	{
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}
