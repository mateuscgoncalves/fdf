/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/24 16:10:42 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_bres_alg(int x0, int y0, int x1, int y1, t_data *data)
{
	int	dx = abs(x1 - x0);
	int	sx = -1;
	if (x0 < x1)
		sx = 1;
	int dy = -abs(y1 - y0);
	int sy = -1;
	if (y0 < y1)
		sy = 1;
	int error = dx + dy;
	int e2;

	while (1)
	{
		my_mlx_pixel_put(data, x0, y0, 0x00FF0000);
		if (x0 == x1 && y0 == 1)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break;
			error = error + dy;
			x0 = x0 + sx;
		} else if (e2 <= dx)
		{
			if (y0 == y1)
				break;
			error = error + dx;
			y0 = y0 + sy;
		}
	}
}
int    main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF");
    img.img = mlx_new_image(mlx, 1000, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    ft_bres_alg(100, 500, 500, 500, &img);
	ft_bres_alg(100, 100, 500, 100, &img);
	ft_bres_alg(100, 100, 100, 500, &img);
	ft_bres_alg(500, 100, 500, 500, &img);
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
