/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:34:07 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:41 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	const char	*f;
	char		*t;

	f = src;
	t = dst;
	if ((f != NULL || t != NULL) && len != 0)
	{
		if (f < t)
		{
			f += len;
			t += len;
			while (len-- > 0)
				*(--t) = *(--f);
		}
		else
			while (len-- > 0)
				*t++ = *f++;
	}
	return (dst);
}
