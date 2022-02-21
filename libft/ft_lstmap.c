/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:25:52 by mgoncalv          #+#    #+#             */
/*   Updated: 2021/12/01 15:47:15 by mgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_element;

	if (!lst)
		return (NULL);
	new_element = ft_lstnew((*f)(lst->content));
	if (!new_element)
	{
		ft_lstclear(&newlist, (*del));
	}
	newlist = new_element;
	lst = lst->next;
	while (lst)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!new_element)
			ft_lstclear(&newlist, (*del));
		ft_lstadd_back(&newlist, new_element);
		lst = lst->next;
	}
	return (newlist);
}
