/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:33:37 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:41 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, int n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	if (n != 0)
	{
		p1 = s1;
		p2 = s2;
		while (n-- != 0)
		{
			if (*p1++ != *p2++)
				return ((int)(*(--p1) - *(--p2)));
		}
	}
	return (0);
}
