/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:48:38 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/11/30 18:20:34 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_src = (unsigned char *) src;
	temp_dest = (unsigned char *) dest;
	if (temp_src < temp_dest)
	{
		while (n--)
			temp_dest[n] = temp_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
