/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:52:02 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 16:19:28 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_reverse_str(char *str)
{
	size_t	size;
	char	temp;
	size_t	i;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
		i++;
	}
	return (str);
}

static int	ft_count_digits(int n)
{
	int	size;
	int	nb;

	if (n < 0)
	{
		size = 2;
		nb = -n;
	}
	else
	{
		nb = n;
		size = 1;
	}
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static char	*ft_add_sign(char *str, int n, int i)
{
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	nb;
	char			*result;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_count_digits(n);
	result = malloc(sizeof (char) * size);
	if (!result)
		return (NULL);
	nb = n;
	i = 0;
	if (n < 0)
		nb = -n;
	while (nb)
	{
		result[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	result = ft_add_sign(result, n, i);
	return (ft_reverse_str(result));
}
