/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:16:07 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/01/20 21:31:27 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	int			ret;

	if (BUFFER_SIZE < 1 || (fd < 0 || fd > 1024))
		return (NULL);
	str = NULL;
	str = ft_strjoin(str, buffer[fd]);
	ret = 1;
	while (ret && ft_nchr(buffer[fd]) == 0)
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(str);
			return (NULL);
		}
		buffer[fd][ret] = '\0';
		str = ft_strjoin(str, buffer[fd]);
	}
	str = ft_getline(str);
	ft_getbuffer(buffer[fd]);
	return (str);
}
