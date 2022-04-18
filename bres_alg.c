/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:59:01 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/18 15:15:58 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bres_alg(t_point point0, t_point point1, t_data *data)
{
	t_point	d;
	t_point	s;
	int		error;
	int		e2;
	int		brk;

	d.x = fabs(point1.x - point0.x);
	s.x = -1;
	if (point0.x < point1.x)
		s.x = 1;
	d.y = -fabs(point1.y - point0.y);
	s.y = -1;
	if (point0.y < point1.y)
		s.y = 1;
	error = d.x + d.y;
	brk = 0;
	while (!brk)
	{
		if (point0.x < WIDTH && point0.y < HEIGHT
			&& point0.x > 0 && point0.y > 0)
			my_mlx_pixel_put(data, point0.x, point0.y, 0x00FFFFFF);
		e2 = 2 * error;
		if (e2 >= d.y)
		{
			if (point0.x == point1.x)
				brk = 1;
			error = error + d.y;
			point0.x = point0.x + s.x;
		}
		else if (e2 <= d.x)
		{
			if (point0.y == point1.y)
				brk = 1;
			error = error + d.x;
			point0.y = point0.y + s.y;
		}
	}
}
