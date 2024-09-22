/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:51:53 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:41 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_sptr(char *s, int tlen)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	if ((tlen -= ((int)ft_strlen(s) - 2)) >= 0)
	{
		count += ft_putstr_s("0x", 2);
		s += 2;
		count += ft_putpad(tlen, 0);
	}
	count += ft_putstr_s(s, -1);
	return (count);
}

void	ft_pad_len_ptr(t_flag *flags, int len)
{
	if (flags->tlen > (int)len)
		flags->plen -= flags->tlen;
	else
		flags->plen -= len;
}

int		ft_putstr_ptr(char *s, t_flag *flags)
{
	int count;

	count = 0;
	if (flags->trunc == 1 && flags->plen == 0 && flags->tlen == 0)
		return (count += ft_putstr_s("0x", 2));
	if (flags->trunc == 1 && flags->plen > 0 && flags->tlen == 0)
	{
		count += ft_putpad(flags->plen - 2, flags->ptype);
		return (count += ft_putstr_s("0x", 2));
	}
	ft_pad_len_ptr(flags, ft_strlen(s));
	if (flags->align == 0)
		count += ft_putpad(flags->plen, flags->ptype);
	count += ft_putstr_sptr(s, flags->tlen);
	if (flags->align == 1)
		count += ft_putpad(flags->plen, 1);
	return (count);
}
