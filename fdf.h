/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:26:49 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 15:28:13 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "parsemap/parsemap.h"
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_draw {
	t_point	d;
	t_point	s;
	int		error;
	int		e2;
	int		brk;
}	t_draw;

typedef struct s_table {
	int	lines;
	int	columns;
}	t_table;

void	ft_bres_alg(t_point point0, t_point point1, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_put_image(t_vars	mlx_v, t_data img);
void	ft_init_map(t_vars	*mlx_v, t_data *img);
void	ft_make_map(int lines, int columns, int	**matrix);
int		ft_close(void *param);
int		key_press(int keycode, void *param);
void	iso(t_point *coord, int lines, int columns);
#endif