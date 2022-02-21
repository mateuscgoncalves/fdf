/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:06:06 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/11/30 16:34:58 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	tg;

	tg = c;
	while (*str)
	{
		if (*str == tg)
			return ((char *)str);
		str++;
	}
	if (!c)
	{
		return ((char *)str);
	}
	return (NULL);
}
