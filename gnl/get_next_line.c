/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:16:07 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/22 16:45:09 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 && s2[0] == '\0')
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

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
