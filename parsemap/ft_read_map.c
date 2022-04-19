/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:01 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 18:54:43 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

static void	ft_exit(void)
{
	ft_putstr_fd("Error: malloc failed.\n", 2);
	exit(1);
}

static void	ft_free_exit(t_list	*column)
{
	ft_putstr_fd("Error: malloc failed.\n", 2);
	ft_free_stack(&column);
	exit(1);
}

static void	ft_add_line(int *columns, char	*line, t_list *column, t_list *new)
{
	new = ft_lstnew(ft_split_ints(line, ' ', *columns));
	if (!new)
		ft_free_exit(column);
	ft_lstadd_back(&column, new);
}

int	**ft_read_map(char *file_name, int *lines, int *columns)
{
	t_list	*column;
	t_list	*new;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	*columns = ft_count_columns(line);
	column = ft_lstnew(ft_split_ints(line, ' ', *columns));
	new = NULL;
	if (!column)
		ft_exit();
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_add_line(columns, line, column, new);
	}
	return (ft_create_matrix(&column, lines));
}
