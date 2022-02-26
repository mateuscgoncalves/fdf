/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:26:49 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/26 20:11:03 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "parsemap/parsemap.h"
#include <math.h>

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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

#endif