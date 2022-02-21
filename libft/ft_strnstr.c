/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:08:08 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 16:17:56 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*haystack_cp;
	char	*needle_cp;

	haystack_cp = (char *) haystack;
	needle_cp = (char *) needle;
	if (*needle_cp == 0)
		return ((char *) haystack_cp);
	needle_len = ft_strlen(needle_cp);
	while (*haystack_cp && len >= needle_len)
	{
		if (*haystack_cp == *needle_cp
			&& ft_strncmp(haystack_cp, needle_cp, needle_len) == 0)
			return ((char *) haystack_cp);
		haystack_cp++;
		len--;
	}
	return (NULL);
}
