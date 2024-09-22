/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:21:09 by dapalmer          #+#    #+#             */
/*   Updated: 2019/11/15 10:38:47 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	if (!alst || !new)
		return ;
	aux = *alst;
	if (!aux)
		*alst = new;
	else
	{
		aux = ft_lstlast(aux);
		aux->next = new;
	}
}
