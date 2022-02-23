/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:01 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 19:46:11 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

int	**ft_read_map(char *file_name, int *lines)
{
	t_list	*column;
	int		fd;
	char	*line;
	int		columns;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	columns = ft_count_columns(line);
	column = ft_lstnew(ft_split_ints(line, ' ', columns));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(&column,
				ft_lstnew(ft_split_ints(line, ' ', columns)));
	}
	return (ft_create_matrix(&column, lines));
}