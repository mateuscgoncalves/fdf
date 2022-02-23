/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <mgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:26 by mgoncalv          #+#    #+#             */
/*   Updated: 2022/02/23 20:35:38 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsemap.h"

void	ft_free_matrix(int	**matrix, int lines)
{
	while (--lines >= 0)
		free(matrix[lines]);
	free(matrix);
}