/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:34:41 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:37:12 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*(str++))
		;
	return ((s == NULL) ? 0 : (int)(str - s - 1));
}
