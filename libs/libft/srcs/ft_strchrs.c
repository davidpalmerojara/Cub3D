/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:34:21 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/11 19:09:13 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrs(const char *s, char *c)
{
	while (*c)
	{
		if (ft_strchr(s, *c))
			return (1);
		c++;
	}
	return (0);
}
