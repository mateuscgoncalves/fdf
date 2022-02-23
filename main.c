/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:01:40 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 18:05:16 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int	*ft_split_ints(char const *s, char c, int size);

int	ft_count_columns(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]) || str[i] == '-')
			c++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (c);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*current;

	while (*stack && stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
	stack = NULL;
}

int	**ft_create_matrix(t_list **stack, int *lines)
{
	t_list	*current;
	int		**matrix;
	int		i;

	if (!stack)
		return (NULL);
	*lines = ft_lstsize(*stack);
	matrix = malloc(sizeof(int *) * *lines);
	if (!matrix)
	{
		ft_lstclear(stack, free);
		return (NULL);
	}
	current = *stack;
	i = 0;
	while (current)
	{
		matrix[i] = (int *) current->content;
		i++;
		current = current->next;
	}
	ft_free_stack(stack);
	return (matrix);
}

int	**ft_read_map(char *file_name, int *lines, int *columns)
{
	t_list	*column;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	*columns = ft_count_columns(line);
	column = ft_lstnew(ft_split_ints(line, ' ', *columns));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(&column,
				ft_lstnew(ft_split_ints(line, ' ', *columns)));
	}
	return (ft_create_matrix(&column, lines));
}

int	main(int argc, char **argv)
{
	int		**matrix;
	int		columns;
	int		lines;

	(void) matrix;
	if (argc != 2)
		return (1);
	matrix = ft_read_map(argv[1], &lines, &columns);
	while (--lines >= 0)
		free(matrix[lines]);
	free(matrix);
	return (0);
}
