/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:20 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 15:54:31 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			len;

	len = count * size;
	s = malloc(len);
	if (!s)
		return (NULL);
	while (len--)
	{
		s[len] = '\0';
	}
	return (s);
}
