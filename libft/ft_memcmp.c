/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:34:19 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/11/30 16:14:21 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;
	size_t			i;

	s1_cp = (unsigned char *) s1;
	s2_cp = (unsigned char *) s2;
	i = 0;
	while (n--)
	{
		if (s1_cp[i] != s2_cp[i])
		{
			return (s1_cp[i] - s2_cp[i]);
		}
		i++;
	}
	return (0);
}
