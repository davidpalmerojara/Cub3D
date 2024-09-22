/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:47:15 by dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:58:50 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_pos *pos)
{
	if (!(pos->img = mlx_new_image(pos->mlx, sW, sH)))
		exit_error(pos);
	pos->addr = (int *)mlx_get_data_addr(pos->img, &pos->bits_per_pixel,
		&pos->line_length, &pos->endian);
}

int			render_next_frame(t_pos *pos)
{
	double z_buffer[sW + 1];

	ft_move(pos);
	ft_rotate(pos);
	ft_draw(pos, z_buffer);
	mlx_put_image_to_window(pos->mlx, pos->win, pos->img, 0, 0);
	return (1);
}

void	ft_unset_mlx(t_pos *pos)
{
	if (!pos->win)
		mlx_destroy_window(pos->mlx, pos->win);
	if (!pos->img)
		mlx_destroy_image(pos->mlx, pos->img);
}

void	ft_init_mlx(t_pos *pos)
{
	if ((pos->mlx = mlx_init()) == NULL)
		ft_unset_mlx(pos);
	if ((pos->win = mlx_new_window(pos->mlx, sW, sH, "cub3D")) == NULL)
		ft_unset_mlx(pos);
}

void	ft_set_values(t_pos *pos)
{
	pos->mlx = mlx_init();
	pos->dX = 0;
	pos->dY = 0;
	pos->pX = 8;
	pos->pY = 3;
	pos->plX = 0;
	pos->plY = 0;
	pos->mu = 0;
	pos->md = 0;
	pos->ml = 0;
	pos->mr = 0;
	pos->rr = 0;
	pos->rl = 0;
	pos->spd = 4;
	pos->map.color[0] = -1;
	pos->map.color[1] = -1;
	pos->map.map = NULL;
}

int			main(int ac, char **av)
{
	t_pos	pos;
	
	if (ac != 2)
		exit(0);
	
	ft_init_mlx(&pos);
	init_image(&pos);
	ft_set_values(&pos);
	ft_read_file(&pos, av);

	mlx_hook(pos.win, 2, 1, key_hook, &pos);
	mlx_hook(pos.win, 3, 10, key_hook_rel, &pos);
	mlx_loop_hook(pos.mlx, render_next_frame, &pos);
	mlx_loop(pos.mlx);
	ft_unset_mlx(&pos);
	exit_game(&pos);
}
