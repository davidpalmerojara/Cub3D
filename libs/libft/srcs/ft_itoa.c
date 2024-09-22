/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:39:45 by dapalmer          #+#    #+#             */
/*   Updated: 2019/11/15 11:06:08 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(char *num)
{
	if (!(num = ft_calloc(2, sizeof(char))))
		return (NULL);
	num[0] = '0';
	return (num);
}

static int	ft_length(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	maxn;

	num = NULL;
	maxn = n;
	len = ft_length(maxn);
	if (n == 0)
		return (ft_zero(num));
	if (!(num = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		maxn *= -1;
	}
	num[len] = '\0';
	len--;
	while (maxn)
	{
		num[len--] = (maxn % 10) + '0';
		maxn /= 10;
	}
	return (num);
}
