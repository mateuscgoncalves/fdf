/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:52:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 17:16:04 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_image(t_vars	mlx_v, t_data img)
{
	mlx_put_image_to_window(mlx_v.mlx, mlx_v.win, img.img, 0, 0);
	mlx_hook(mlx_v.win, 2, 0, key_press, &mlx_v);
	mlx_hook(mlx_v.win, 17, 0, ft_close, &mlx_v);
	mlx_loop(mlx_v.mlx);
}

void	ft_init_map(t_vars	*mlx_v, t_data *img)
{
	mlx_v->mlx = mlx_init();
	mlx_v->win = mlx_new_window(mlx_v->mlx, 1500, 1000, "FDF");
	img->img = mlx_new_image(mlx_v->mlx, 1500, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	ft_put_map(int **matrix, t_point **result_matrix, t_table table,
t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < table.lines)
	{
		j = 0;
		result_matrix[i] = (t_point *) malloc(sizeof(t_point) * table.columns);
		while (j < table.columns)
		{
			result_matrix[i][j].x = j;
			result_matrix[i][j].y = i;
			result_matrix[i][j].z = matrix[i][j];
			iso(&result_matrix[i][j], table.lines, table.columns);
			if (j > 0)
				ft_bres_alg(result_matrix[i][j - 1], result_matrix[i][j], img);
			if (i > 0)
				ft_bres_alg(result_matrix[i - 1][j], result_matrix[i][j], img);
			j++;
		}
		i++;
	}
}

void	ft_make_map(int lines, int columns, int	**matrix,
	t_point **result_matrix)
{
	t_vars	mlx_v;
	t_data	img;
	t_table	table;

	table.lines = lines;
	table.columns = columns;
	ft_init_map(&mlx_v, &img);
	ft_put_map(matrix, result_matrix, table, &img);
	ft_put_image(mlx_v, img);
}
