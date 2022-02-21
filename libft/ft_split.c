/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:17 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/21 18:46:13 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char sep)
{
	int	index;
	int	word;

	index = 0;
	word = 0;
	while (str[index])
	{
		while (str[index] && str[index] == sep)
			index++;
		if (str[index] && str[index] != sep)
		{
			word++;
			while (str[index] && str[index] != sep)
				index++;
		}
	}
	return (word);
}

static char	*ft_malloc_word(char const *str, char sep)
{
	int		index;
	char	*word;

	index = 0;
	while (str[index] && str[index] != sep)
		index++;
	word = malloc(sizeof(char) * (index + 1));
	if (!word)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != sep)
	{
		word[index] = str[index];
		index++;
	}
	word[index] = 0;
	return (word);
}

static int	ft_free_tab(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	ft_fill_tab(char const *s, char c, char **tab)
{
	int		index;
	char	*word;

	index = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word = ft_malloc_word(s, c);
			if (!word)
				return (ft_free_tab(tab, index));
			tab[index] = word;
			index++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[index] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	if (!ft_fill_tab(s, c, tab))
		return (NULL);
	return (tab);
}
