/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:31:09 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 15:30:10 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_size;
	size_t	i;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	new_size = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	result = malloc(sizeof(char) * (new_size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
	{
		result[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		result[i] = *s2;
		s2++;
		i++;
	}
	result[i] = 0;
	return (result);
}
