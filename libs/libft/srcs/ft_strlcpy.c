/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:34:34 by dapalmer          #+#    #+#             */
/*   Updated: 2021/07/21 13:20:05 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlcpy(char *dst, const char *src, int dstsize)
{
	const char	*s;
	int		n;

	if (dst == NULL || src == NULL)
		return ((int)((src == NULL) ? src : dst));
	s = src;
	n = dstsize;
	if (n != 0)
		while (--n != 0)
			if ((*dst++ = *src++) == '\0')
				break ;
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return ((int)(src - s - 1));
}
