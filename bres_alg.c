/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:59:01 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 15:09:37 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_point point0, t_point point1, t_data *data, t_draw draw)
{
	while (!draw.brk)
	{
		if (point0.x < WIDTH && point0.y < HEIGHT
			&& point0.x > 0 && point0.y > 0)
			my_mlx_pixel_put(data, point0.x, point0.y, 0x00FFFFFF);
		draw.e2 = 2 * draw.error;
		if (draw.e2 >= draw.d.y)
		{
			if (point0.x == point1.x)
				draw.brk = 1;
			draw.error = draw.error + draw.d.y;
			point0.x = point0.x + draw.s.x;
		}
		else if (draw.e2 <= draw.d.x)
		{
			if (point0.y == point1.y)
				draw.brk = 1;
			draw.error = draw.error + draw.d.x;
			point0.y = point0.y + draw.s.y;
		}
	}
}

void	ft_bres_alg(t_point point0, t_point point1, t_data *data)
{
	t_draw	draw;

	draw.d.x = fabs(point1.x - point0.x);
	draw.s.x = -1;
	if (point0.x < point1.x)
		draw.s.x = 1;
	draw.d.y = -fabs(point1.y - point0.y);
	draw.s.y = -1;
	if (point0.y < point1.y)
		draw.s.y = 1;
	draw.error = draw.d.x + draw.d.y;
	draw.brk = 0;
	ft_draw(point0, point1, data, draw);
}
