/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:33:22 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:41 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	unsigned char		*mdst;
	const unsigned char	*msrc;

	mdst = (unsigned char *)dst;
	msrc = (const unsigned char *)src;
	if (n)
	{
		while (n-- != 0)
			if ((*mdst++ = *msrc++) == (unsigned char)c)
				return (mdst);
	}
	return (NULL);
}
