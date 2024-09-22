/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:35:10 by dapalmer          #+#    #+#             */
/*   Updated: 2019/11/21 12:35:12 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *t;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	t = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			t = (char *)s;
		s++;
	}
	return (t);
}
