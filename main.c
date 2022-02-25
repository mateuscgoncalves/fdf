/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/25 22:46:15 by mgoncalv         ###   ########.fr       */
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
		printf("x: %d y: %d\n", point0.x, point0.y);
		printf("brk: %d\n", brk);
		printf("Here 0\n");
		my_mlx_pixel_put(data, point0.x, point0.y, 0x00FF0000);
		// if (point0.x == point1.x && point0.y == 1)
		// 	brk = 1;
		printf("brk: %d\n", brk);
		e2 = 2 * error;
		if (e2 >= d.y)
		{
			printf("Here 1\n");
			if (point0.x == point1.x)
				brk = 1;
			printf("brk: %d\n", brk);
			error = error + d.y;
			point0.x = point0.x + s.x;
		} else if (e2 <= d.x)
		{
			printf("Here 2\n");
			if (point0.y == point1.y)
				brk = 1;
			printf("brk: %d\n", brk);
			error = error + d.x;
			point0.y = point0.y + s.y;
		}
		printf("Here 3\n");
	}
	printf("Here 4\n");
}
// int    main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data    img;
// 	t_point point;
// 	t_point point2;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF");
//     img.img = mlx_new_image(mlx, 1000, 1000);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//                                  &img.endian);

// 	point.x = 100;
// 	point.y = 500;

// 	point2.x = 200;
// 	point2.y = 600;

//     ft_bres_alg(point, point2, &img);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
// }

void	ft_make_map(int lines, int columns)
{
	void    *mlx;
    void    *mlx_win;
    t_data    img;
	t_point point;
	t_point point2;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 2000, 2000, "FDF");
    img.img = mlx_new_image(mlx, 2000, 2000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	
	printf("Lines: %d Columns: %d\n", lines, columns);
	// point.x = 10;
	// point.y = 0;

	// point2.x = 10;
	// point2.y = 50;
	int i = 0;
	int	j;
	int scale = 25;
	while (i < lines)
	{
		j = 0;
		while (j < columns)
		{
			
			if (j + 1 < columns)
			{
				
				point.x = j * scale;
				point.y = i * scale;
				point2.x = (j + 1) * scale;
				point2.y = i * scale;
				ft_bres_alg(point, point2, &img);
				
				// my_mlx_pixel_put(&img, point.x, point.y, 0x00FF0000);
			}
			if (i + 1 < lines)
			{
				point.x = j * scale;
				point.y = i * scale;
				point2.x = j * scale;
				point2.y = (i + 1) * scale;
				printf("Lines: %d x: %d, y: %d\n", lines, j * scale, (i + 1) * scale);
				ft_bres_alg(point, point2, &img);
			}
			if (i > 0 && j + 1 < columns)
			{
				point.x = j * scale;
				point.y = i * scale;
				point2.x = (j + 1) * scale;
				point2.y = (i - 1) * scale;
				printf("Lines: %d x: %d, y: %d\n", lines, j * scale, (i + 1) * scale);
				ft_bres_alg(point, point2, &img);
			}
			
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);

	
}
int	main(int argc, char **argv)
{
	int		**matrix;
	int		lines;
	int		columns;

	if (argc != 2)
		return (1);
	matrix = ft_read_map(argv[1], &lines, &columns);

	ft_make_map(lines, columns);

	ft_free_matrix(matrix, lines);
	return (0);
}
