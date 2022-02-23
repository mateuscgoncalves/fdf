/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:05 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 19:46:03 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

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