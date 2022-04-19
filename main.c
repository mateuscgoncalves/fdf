/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 18:48:16 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	iso(t_point *coord, int lines, int columns)
{
	double	previous_x;
	double	previous_y;

	coord->x = round(coord->x - columns / 2);
	coord->y = round(coord->y - lines / 2);
	previous_x = coord->x;
	previous_y = coord->y;
	coord->x = round((previous_x - previous_y)
			* cos(0.523599) * HEIGHT / round(columns * 1.5));
	coord->y = round(-(coord->z * 5) + (previous_x + previous_y)
			* sin(0.523599) * HEIGHT / round(columns * 1.5));
	coord->z = round(coord->z);
	coord->x = coord->x + WIDTH / 2;
	coord->y = coord->y + HEIGHT / 2;
}

int	main(int argc, char **argv)
{
	t_maps	map;

	if (argc != 2)
		return (1);
	map.matrix = ft_read_map(argv[1], &(map.lines), &(map.columns));
	map.result_matrix = (t_point **)malloc(sizeof(t_point *) * map.lines);
	if (map.result_matrix == NULL)
	{
		ft_free_matrix(map.matrix, map.lines);
		ft_putstr_fd("Error: malloc failed.\n", 2);
		exit(1);
	}
	ft_make_map(map);
	ft_free_all(map);
	return (0);
}
