/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:57:56 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 16:23:27 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strnlen(char *str, unsigned int size)
{
	size_t	i;

	i = 0;
	while (str[i] && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;

	i = 0;
	destlen = ft_strnlen((char *) dest, dstsize);
	if (dstsize == 0)
		return (ft_strlen((char *) src));
	if (dstsize == destlen)
		return (ft_strlen((char *) src) + dstsize);
	while (src[i] && (destlen + i) < (dstsize - 1))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + ft_strlen((char *)src));
}
