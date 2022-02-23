/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:42 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 20:35:19 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSEMAP_H
# define PARSEMAP_H

# include "stdlib.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

int		ft_count_columns(char *str);
int		**ft_create_matrix(t_list **stack, int *lines);
void	ft_free_matrix(int	**matrix, int lines);
void	ft_free_stack(t_list **stack);
int		**ft_read_map(char *file_name, int *lines);
int		*ft_split_ints(char const *s, char c, int size);

#endif