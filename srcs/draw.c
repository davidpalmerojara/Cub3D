/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos->draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:48:54 by dapalmer          #+#    #+#             */
/*   Updated: 2021/02/05 13:00:44 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_draw_wall(t_pos *pos, int x, int y)
{
	int		texture = 0;
	int		buffer;
	
	buffer = 0;
	texture = ft_textures(pos, 0);
	while (y++ < pos->draw.dEnd)
	{
		pos->draw.texPos += (1.0 * tH / ((int)(sH / pos->draw.perpWallDist)));
		buffer = get_tex_color(&pos->tex[texture],
			pos->draw.texX, ((int)pos->draw.texPos & (tH - 1)));
		if (pos->draw.side == 1)
		{
			texture = ft_textures(pos, 1);
			buffer = get_tex_color(&pos->tex[texture],
			pos->draw.texX, ((int)pos->draw.texPos & (tH - 1)));
		}
		my_mlx_pixel_put(pos, x, y, buffer);
	}
	return y;
}

void	ft_draw(t_pos *pos, double *z_buffer)
{
	int x;
	int y;
	
	x = 0;
	while (x++ < sW)
	{
		y = 0;
		ft_calculate_wall(z_buffer, pos, x);
		while (y++ < pos->draw.dStart)
			my_mlx_pixel_put(pos, x, y, pos->map.color[1]);
		y = ft_draw_wall(pos, x, y);
		while (y++ < sH)
			my_mlx_pixel_put(pos, x, y, pos->map.color[0]);
	}
}