/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:39 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/04/19 14:16:18 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

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
