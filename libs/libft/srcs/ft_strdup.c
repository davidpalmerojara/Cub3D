/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:17:27 by dapalmer          #+#    #+#             */
/*   Updated: 2019/11/20 16:10:15 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	len = -1;
	while (s1[++len])
		dest[len] = s1[len];
	dest[len] = '\0';
	return (dest);
}
