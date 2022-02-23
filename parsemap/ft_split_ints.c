/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:17 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 19:46:23 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

static int	ft_fill_tab(char const *s, char c, int *tab)
{
	int	index;
	int	number;

	index = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			number = ft_atoi(s);
			tab[index] = number;
			index++;
			while (*s && *s != c)
				s++;
		}
	}
	return (1);
}

int	*ft_split_ints(char const *s, char c, int size)
{
	int	*tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(int *) * size);
	if (!tab)
		return (NULL);
	if (!ft_fill_tab(s, c, tab))
		return (NULL);
	return (tab);
}
