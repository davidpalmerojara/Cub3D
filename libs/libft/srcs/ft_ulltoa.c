/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:51:14 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:41 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_swap(char *a, char *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

char			*ft_strrev(char *str, int start)
{
	int len;

	start--;
	len = ft_strlen(str);
	while (++start < --len)
		ft_swap(&str[start], &str[len]);
	return (str);
}

int			ft_nbrlenbase_ull(unsigned long long number, int base)
{
	int len;

	len = 1;
	if (base == 1)
		return ((int)number + len);
	while (number /= base)
		len++;
	return (len);
}

static char		*ft_convert(unsigned long long n, \
							const unsigned base, \
							char *str, int i)
{
	int			res;
	char		*bstr;

	res = 0;
	bstr = "0123456789abcdefghijklmnopqrstuvqxyz";
	while (base == 1 && (i++ <= ft_nbrlenbase_ull(n, base)))
	{
		str[i] = '1';
		if (i == ft_nbrlenbase_ull(n, base) - 1)
			return (str);
	}
	if (n > 0)
	{
		res = n % base;
		str[i++] = bstr[res];
		ft_convert(n / base, base, str, i);
	}
	return (str);
}

char			*ft_ulltoa(unsigned long long nb, const unsigned base)
{
	int			nb_len;
	char		*str;

	nb_len = 0;
	if (base <= 0)
		return (NULL);
	if (!nb)
		return (ft_strdup("0"));
	nb_len = ft_nbrlenbase_ull(nb, base);
	if ((str = (char *)ft_calloc(nb_len + 1, sizeof(char))))
	{
		str = ft_convert(nb, base, str, 0);
		str[nb_len] = '\0';
		str = ft_strrev(str, 0);
	}
	return (str);
}
