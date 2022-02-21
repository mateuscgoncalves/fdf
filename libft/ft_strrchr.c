/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:57:52 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/11/30 17:20:41 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	tg;

	tg = (unsigned char) c;
	last = NULL;
	while (*s)
	{
		if (*s == tg)
		{
			last = (char *)s;
		}
		s++;
	}
	if (!c)
		return ((char *)s);
	return (last);
}
