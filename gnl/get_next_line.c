/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:16:07 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/19 20:20:22 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_nchr(str);
	if (j == 0)
		return (str);
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[i] = str[i];
		i++;
	}
	line[j] = '\0';
	free(str);
	return (line);
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str = NULL;
	str = ft_strjoin(str, buffer);
	ret = 1;
	while (ret && ft_nchr(buffer) == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(str);
			return (NULL);
		}
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	str = ft_getline(str);
	ft_getbuffer(buffer);
	return (str);
}
