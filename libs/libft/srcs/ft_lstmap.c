/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:12:41 by dapalmer          #+#    #+#             */
/*   Updated: 2019/11/15 10:46:34 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*head;

	if (!lst)
		return (NULL);
	if (!(current = ft_lstnew(f(lst->content))))
		return (NULL);
	head = current;
	while (lst)
	{
		if (lst->next)
		{
			if (!(current->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&head, del);
				return (0);
			}
			current = current->next;
		}
		lst = lst->next;
	}
	current->next = NULL;
	return (head);
}
