/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:47:15 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 18:48:11 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(void *param)
{
	(void) param;
	exit(0);
	return (0);
}

int	key_press(int keycode, void *param)
{
	if (keycode == 53)
		ft_close(param);
	return (0);
}

void	ft_free_all(t_maps map)
{
	while (--map.lines >= 0)
	{
		free(map.result_matrix[map.lines]);
		free(map.matrix[map.lines]);
	}
	free(map.result_matrix);
	free(map.matrix);
}
