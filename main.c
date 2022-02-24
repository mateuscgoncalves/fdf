/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/24 16:26:28 by mgoncalv         ###   ########.fr       */
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
	int error;
	int e2;
	int	brk;
	
	d.x = abs(point1.x - point0.x);
	s.x = -1;
	if (point0.x < point1.x)
		s.x = 1;
	d.y = -abs(point1.y - point0.y);
	s.y = -1;
	if (point0.y < point1.y)
		s.y = 1;
	error = d.x + d.y;
	brk = 0;
	while (!brk)
	{
		my_mlx_pixel_put(data, point0.x, point0.y, 0x00FF0000);
		if (point0.x == point1.x && point0.y == 1)
			brk = 1;
		e2 = 2 * error;
		if (e2 >= d.y)
		{
			if (point0.x == point1.x)
				brk = 1;
			error = error + d.y;
			point0.x = point0.x + s.x;
		} else if (e2 <= d.x)
		{
			if (point0.y == point1.y)
				brk = 1;
			error = error + d.x;
			point0.y = point0.y + s.y;
		}
	}
}
int    main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;
	t_point point;
	t_point point2;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF");
    img.img = mlx_new_image(mlx, 1000, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

	point.x = 100;
	point.y = 500;

	point2.x = 200;
	point2.y = 600;

    ft_bres_alg(point, point2, &img);
	// ft_bres_alg(100, 100, 500, 100, &img);
	// ft_bres_alg(100, 100, 100, 500, &img);
	// ft_bres_alg(500, 100, 500, 500, &img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
// int	main(int argc, char **argv)
// {
// 	int		**matrix;
// 	int		lines;

// 	if (argc != 2)
// 		return (1);
// 	matrix = ft_read_map(argv[1], &lines);
// 	ft_free_matrix(matrix, lines);
// 	return (0);
// }
