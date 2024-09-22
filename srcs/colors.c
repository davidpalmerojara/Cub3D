/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:45:09 by dapalmer          #+#    #+#             */
/*   Updated: 2021/07/29 07:36:44 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isrgb(char *c)
{
	int count;
	
	count = 0;
	while (*c)
	{
		if (*c == ',' || *c == 'C' || *c == 'F')
			count++;
		if (ft_isdigit(*c) || *c == ' ' || *c == ',' || *c == 'C' || *c == 'F')
			c++;
		else
			return 0;
	}
    if (count != 3)
        return 0;
	return 1;
}

void     ft_rgb(int num, t_pos *pos, char *line)
{
    int     boolean;
    int     color;
    int     r;
    int     g;
    int     b;
    int i;
    boolean = 0;
    
    color = 0;
    i = 0;
    
    
    //if (!ft_isrgb(line))
    //    exit_error(pos);
    while (*line && boolean < 3)
    {
        while (!ft_isdigit(*line))
            line++;
        color = 0;
        while (ft_isdigit(*line))
        {
            color = color * 10 + (*line - '0');
            line++;
        } 
        if (color >= 0 && color <= 255)
        {
            if (boolean == 0)
                r = color;
            else if (boolean == 1)
                g = color;
            else
                b = color;
        }
        else
            exit_error(pos);
        boolean++;
        
    }
    if (boolean != 3)
        exit_error(pos);
    pos->map.color[num] = create_trgb(1, r, g, b);
    
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		my_mlx_pixel_put(t_pos *pos, int x, int y, int color)
{
	char	*dst;

	dst = (char *)pos->addr + (y * pos->line_length + x * (pos->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
