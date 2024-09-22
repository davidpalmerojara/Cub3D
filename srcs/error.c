/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:57:25 by Dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:57:26 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void     exit_error(t_pos *pos)
{
    int i = 0;

    if (pos->map.mH)
        while (i < pos->map.mH)
        {
            free(pos->map.world[i]);
            pos->map.world[i] = NULL;
            i++;
        }
    
    if (pos->map.world)
        free(pos->map.world);
    pos->map.world = NULL;
    
    mlx_destroy_image(pos->mlx, pos->img);
    mlx_destroy_window(pos->mlx, pos->win);
    //ft_printf("Exit\n");
    exit(0);
}