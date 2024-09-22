/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:29:52 by Dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:57:40 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_tex_color(t_tex *tex, int x, int y)
{
	if (x >= 0 && x < tex->width && y >= 0 && y < tex->height)
	{
		return (*(int*)(tex->ptr
			+ (4 * tex->width * (int)y)
			+ (4 * (int)x)));
	}
	return (0x0);
}

int			ft_textures(t_pos *pos, int sides)
{
	if (!sides)
	{
		if ((double)pos->draw.mapX < pos->pX)
			return 0;
		if ((double)pos->draw.mapX > pos->pX)
			return 1;
	}
	else
	{
		if ((double)pos->draw.mapY < pos->pY)
			return 3;
		if ((double)pos->draw.mapY > pos->pY)
			return 2;
	}
	return pos->map.world[pos->draw.mapX][pos->draw.mapY];
}

void    ft_load_texture(t_pos *pos, char *line, int i) 
{
		while (*line != '.')
        	line++;
        pos->tex[i].tex = mlx_xpm_file_to_image(pos->mlx, line, &pos->tex[i].width, &pos->tex[i].height);
        pos->tex[i].ptr = mlx_get_data_addr(pos->tex[i].tex, &pos->tex[i].bpp, &pos->tex[i].size_line, &pos->tex[i].endian);
        
}