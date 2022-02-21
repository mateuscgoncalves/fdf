/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:54:00 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 16:23:55 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_in_charset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	size;
	int	new_size;
	int	i;
	int	j;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	new_size = size;
	i = 0;
	while (s1[i] && ft_is_in_charset(s1[i], set))
	{
		i++;
		new_size--;
	}
	if (new_size <= 0)
		return (ft_strdup(""));
	j = 1;
	while (s1[size - j] && ft_is_in_charset(s1[size - j], set))
	{
		new_size--;
		j++;
	}
	return (ft_substr(&s1[i], 0, new_size));
}
