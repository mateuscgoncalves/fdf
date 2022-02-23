/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 21:10:33 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_bres_alg(int x1, int x2, int y1, int y2, t_data *data)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = 2 * dy - dx;

	while (x1 <= x2)
	{
		my_mlx_pixel_put(data, x1, y1, 0x00FF0000);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y1++;
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

    ft_bres_alg(100, 450, 100, 500, &img);
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
