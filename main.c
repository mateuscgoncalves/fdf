/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/11 15:43:58 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

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
		if (point0.x < WIDTH && point0.y < HEIGHT && point0.x > 0 && point0.y > 0)
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

static void	iso(double *x, double *y, double *z, int lines, int columns)
{
	double	previous_x;
	double	previous_y;

	*x = round(*x - columns / 2);
	*y = round(*y - lines / 2);
	previous_x = *x;
	previous_y = *y;
	*x = round((previous_x - previous_y)
			* cos(0.523599) * HEIGHT / round(columns * 1.5));
	*y = round(-(*z * 5) + (previous_x + previous_y)
			* sin(0.523599) * HEIGHT / round(columns * 1.5));
	*z = round(*z);
	// printf("Lines: %i x Columns: %i\n", lines, columns);
	*x = *x + WIDTH / 2;
	*y = *y + HEIGHT / 2;
	// *z = *z * 10;
}

static int	ft_close(void *param)
{
	(void) param;
	exit(0);
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
			iso(&result_matrix[i][j].x,
				&result_matrix[i][j].y, &result_matrix[i][j].z, lines, columns);
			if (j > 0)
				ft_bres_alg(result_matrix[i][j - 1], result_matrix[i][j], &img);
			if (i > 0)
				ft_bres_alg(result_matrix[i - 1][j], result_matrix[i][j], &img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_v.mlx, mlx_v.win, img.img, 0, 0);
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
