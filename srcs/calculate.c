/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:14:37 by Dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:30:17 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_calculate_dda(t_pos *pos, int x)
{
	while (pos->map.world[pos->draw.mapX][pos->draw.mapY] <= 0)
	{
		if (pos->draw.sDistX < pos->draw.sDistY)
		{
			pos->draw.sDistX += fabs((1 / (pos->dX + pos->plX *
				(2 * x / (double)sW - 1))));
			pos->draw.mapX += pos->draw.stepX;
			pos->draw.side = 0;
		}
		else
		{
			pos->draw.sDistY += fabs((1 / (pos->dY + pos->plY *
				(2 * x / (double)sW - 1))));
			pos->draw.mapY += pos->draw.stepY;
			pos->draw.side = 1;
		}
	}
}

void		ft_calculate_sdist(t_pos *pos, int x)
{
	if ((pos->dX + pos->plX * (2 * x / (double)sW - 1)) < 0)
	{
		pos->draw.stepX = -1;
		pos->draw.sDistX = (pos->pX - pos->draw.mapX) *
			fabs((1 / (pos->dX + pos->plX * (2 * x / (double)sW - 1))));
	}
	else
	{
		pos->draw.stepX = 1;
		pos->draw.sDistX = (pos->draw.mapX + 1.0 - pos->pX) *
			fabs((1 / (pos->dX + pos->plX * (2 * x / (double)sW - 1))));
	}
	if ((pos->dY + pos->plY * (2 * x / (double)sW - 1)) < 0)
	{
		pos->draw.stepY = -1;
		pos->draw.sDistY = (pos->pY - pos->draw.mapY) *
			fabs((1 / (pos->dY + pos->plY * (2 * x / (double)sW - 1))));
	}
	else
	{
		pos->draw.stepY = 1;
		pos->draw.sDistY = (pos->draw.mapY + 1.0 - pos->pY) *
			fabs((1 / (pos->dY + pos->plY * (2 * x / (double)sW - 1))));
	}
}

void		ft_calculate_values(t_pos *pos, int x)
{
	if (pos->draw.side == 0)
		pos->draw.perpWallDist = (pos->draw.mapX - pos->pX + (1 - pos->draw.stepX) / 2) /
			(pos->dX + pos->plX * (2 * x / (double)sW - 1));
	else
		pos->draw.perpWallDist = (pos->draw.mapY - pos->pY + (1 - pos->draw.stepY) / 2) /
			(pos->dY + pos->plY * (2 * x / (double)sW - 1));
	pos->draw.dStart = -((int)(sH / pos->draw.perpWallDist)) / 2 + sH / 2;
	if (pos->draw.dStart < 0)
		pos->draw.dStart = 0;
	pos->draw.dEnd = ((int)(sH / pos->draw.perpWallDist)) / 2 + sH / 2;
	if (pos->draw.dEnd >= sH)
		pos->draw.dEnd = sH - 1;
	if (pos->draw.side == 0)
		pos->draw.wallX = pos->pY + pos->draw.perpWallDist *
			(pos->dY + pos->plY * (2 * x / (double)sW - 1));
	else
		pos->draw.wallX = pos->pX + pos->draw.perpWallDist *
			(pos->dX + pos->plX * (2 * x / (double)sW - 1));
	pos->draw.wallX -= floor((pos->draw.wallX));
	pos->draw.texX = (int)(pos->draw.wallX * (double)tW);
}

void		ft_calculate_wall(double *z_buffer, t_pos *pos, int x)
{
	pos->draw.mapX = (int)pos->pX;
	pos->draw.mapY = (int)pos->pY;
	ft_calculate_sdist(pos, x);
	ft_calculate_dda(pos, x);
	ft_calculate_values(pos, x);
	if (pos->draw.side == 0 && (pos->dX + pos->plX *
		(2 * x / (double)sW - 1)) > 0)
		pos->draw.texX = tW - pos->draw.texX - 1;
	if (pos->draw.side == 1 && (pos->dY + pos->plY *
		(2 * x / (double)sW - 1)) < 0)
		pos->draw.texX = tW - pos->draw.texX - 1;
	pos->draw.texPos = (pos->draw.dStart - sH / 2 +
		((int)(sH / pos->draw.perpWallDist)) / 2) *
		(1.0 * tH / ((int)(sH / pos->draw.perpWallDist)));
	z_buffer[x] = pos->draw.perpWallDist;
}