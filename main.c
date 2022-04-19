/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 14:54:55 by mgoncalv         ###   ########.fr       */
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

int	ft_close(void *param)
{
	(void) param;
	printf("Hey\n");
	exit(0);
}

int	key_press(int keycode, void *param)
{
	(void) param;
	printf("Key: %d\n", keycode);
	if (keycode == 53)
		exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		**matrix;
	int		lines;
	int		columns;

	if (argc != 2)
		return (1);
	matrix = ft_read_map(argv[1], &lines, &columns);
	ft_make_map(lines, columns, matrix);
	ft_free_matrix(matrix, lines);
	return (0);
}
