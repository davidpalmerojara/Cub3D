/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:46:53 by dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:59:34 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_pos *pos)
{
	ft_unset_mlx(pos);
	
	int i = 0;
    while (i < pos->map.mH)
    {
        free(pos->map.world[i]);
        pos->map.world[i] = NULL;
        i++;
    }
	mlx_destroy_image(pos->mlx, pos->tex[0].tex);
    free(pos->map.world);
	pos->map.world = NULL;
	ft_printf("Exit");
	exit(0);
}

void		ft_rotate(t_pos *pos)
{
	double	new_dx;
	double	new_plx;

	if (pos->rr)
	{
		new_dx = pos->dX;
		pos->dX = pos->dX * cos(0.02 * pos->spd) - pos->dY * sin(0.02 * pos->spd);
		pos->dY = new_dx * sin(0.02 * pos->spd) + pos->dY * cos(0.02 * pos->spd);
		new_plx = pos->plX;
		pos->plX = pos->plX * cos(0.02 * pos->spd) - pos->plY * sin(0.02 * pos->spd);
		pos->plY = new_plx * sin(0.02 * pos->spd) + pos->plY * cos(0.02 * pos->spd);
	}
	if (pos->rl)
	{
		new_dx = pos->dX;
		pos->dX = pos->dX * cos(-0.02 * pos->spd) - pos->dY * sin(-0.02 * pos->spd);
		pos->dY = new_dx * sin(-0.02 * pos->spd) + pos->dY * cos(-0.02 * pos->spd);
		new_plx = pos->plX;
		pos->plX = pos->plX * cos(-0.02 * pos->spd) - pos->plY * sin(-0.02 * pos->spd);
		pos->plY = new_plx * sin(-0.02 * pos->spd) + pos->plY * cos(-0.02 * pos->spd);
	}
}

void		ft_move(t_pos *pos)
{
	if (pos->mu)
	{
			if (pos->map.world[(int)(pos->pX + pos->dX)][(int)pos->pY] == 0)
				pos->pX += pos->dX * (0.035 * pos->spd);
			if (pos->map.world[(int)pos->pX][(int)(pos->pY + pos->dY * (0.035 * pos->spd))] == 0)
				pos->pY += pos->dY * (0.035 * pos->spd);
	}
	if (pos->md)
	{
		if (pos->map.world[(int)(pos->pX - pos->dX)][(int)pos->pY] == 0)
			pos->pX -= pos->dX * (0.035 * pos->spd);
		if (pos->map.world[(int)pos->pX][(int)(pos->pY - pos->dY * (0.035 * pos->spd))] == 0)
			pos->pY -= pos->dY * (0.035 * pos->spd);
	}
	
	if (pos->mr)
	{
		if (pos->map.world[(int)(pos->pX + pos->plX)][(int)pos->pY] == 0)
			pos->pX += pos->plX * (0.035 * pos->spd);
		if (pos->map.world[(int)pos->pX][(int)(pos->pY + pos->plY * (0.035 * pos->spd))] == 0)
			pos->pY += pos->plY * (0.035 * pos->spd);
	}
	
	if (pos->ml)
	{
		if (pos->map.world[(int)(pos->pX - pos->plX)][(int)pos->pY] == 0)
			pos->pX -= pos->plX * (0.035 * pos->spd);
		if (pos->map.world[(int)pos->pX][(int)(pos->pY - pos->plY * (0.035 * pos->spd))] == 0)
			pos->pY -= pos->plY * (0.035 * pos->spd);
	}
}

int		key_hook_rel(int keycode, t_pos *pos)
{
	if (keycode == 13)
		pos->mu = 0;
	if (keycode == 1)
		pos->md = 0;
	if (keycode == 2)
		pos->mr = 0;
	if (keycode == 0)
		pos->ml = 0;
	if (keycode == 124)
		pos->rl = 0;
	if (keycode == 123)
		pos->rr = 0;
	if (keycode == 257 || keycode == 258)
		pos->spd = 1;
	return (1);
}

int			key_hook(int keycode, t_pos *pos)
{
	if (keycode == 53)
		exit_game(pos);
	if (keycode == 13)
		pos->mu= 1;
	if (keycode == 1)
		pos->md = 1;
	if (keycode == 2)
		pos->mr = 1;
	if (keycode == 0)
		pos->ml = 1;
	if (keycode == 124)
		pos->rl = 1;
	if (keycode == 123)
		pos->rr = 1;
	if (keycode == 257 || keycode == 258)
		pos->spd = 2;
	return (1);
}
