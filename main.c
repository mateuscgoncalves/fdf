/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/18 16:07:03 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//Usar t_point
static void	iso(t_point *coord, int lines, int columns)
{
	double	previous_x;
	double	previous_y;
	// int		zoom;

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

static int	ft_close(void *param)
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

void	ft_make_map(int lines, int columns, int	**matrix)
{
	t_vars	mlx_v;
	t_data	img;
	t_point	result_matrix[lines][columns];
	int		i;
	int		j;

	mlx_v.mlx = mlx_init();
	mlx_v.win = mlx_new_window(mlx_v.mlx, 1500, 1000, "FDF");
	img.img = mlx_new_image(mlx_v.mlx, 1500, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			result_matrix[i][j].x = j;
			result_matrix[i][j].y = i;
			result_matrix[i][j].z = matrix[i][j];
			iso(&result_matrix[i][j], lines, columns);
			if (j > 0)
				ft_bres_alg(result_matrix[i][j - 1], result_matrix[i][j], &img);
			if (i > 0)
				ft_bres_alg(result_matrix[i - 1][j], result_matrix[i][j], &img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_v.mlx, mlx_v.win, img.img, 0, 0);
	mlx_hook(mlx_v.win, 2, 0, key_press, &mlx_v);
	mlx_hook(mlx_v.win, 17, 0, ft_close, &mlx_v);
	mlx_loop(mlx_v.mlx);
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
