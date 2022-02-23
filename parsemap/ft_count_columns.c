/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:42 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 20:34:53 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

int	ft_count_columns(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]) || str[i] == '-')
			c++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (c);
}