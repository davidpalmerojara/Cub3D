/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:56:53 by Dapalmer          #+#    #+#             */
/*   Updated: 2021/10/19 10:56:56 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void    ft_check_map(t_pos *pos)
{
    int i;
    int j;
 
    i = -1;
    while (i++ < pos->map.mH)
    {
        j = -1;
        while (j++ < pos->map.mW)
        {
            if (pos->map.world[i][j] == 0)
            {
                if (pos->map.world[i + 1][j] != 0 && pos->map.world[i + 1][j] != 1)
                    exit_error(pos);
                if (pos->map.world[i - 1][j] != 0 && pos->map.world[i - 1][j] != 1)
                    exit_error(pos);
                if (pos->map.world[i][j + 1] != 0 && pos->map.world[i][j + 1] != 1)
                    exit_error(pos);
                if (pos->map.world[i][j - 1] != 0 && pos->map.world[i][j - 1] != 1)
                    exit_error(pos);
            }
        }
    }
}

void		ft_set_position(t_pos *pos, char ori, int i, int j)
{
    pos->pX = (double)i + 0.5;
    pos->pY = (double)j + 0.5;
	if (ori == 'W')
	{
		pos->dY = -0.99;
		pos->plX = -0.80;
	}
	if (ori == 'E')
	{
		pos->dY = 0.99;
		pos->plX = 0.80;
	}
	if (ori == 'S')
	{
		pos->dX = 0.99;
		pos->plY = -0.80;
	}
	if (ori == 'N')
	{
		pos->dX = -0.99;
		pos->plY = 0.80;
	}
}

void ft_set_map(t_pos *pos, char c, int i, int j)
{
    if (c == '0')
        pos->map.world[i][j] = 0;
    if (c == '1')
        pos->map.world[i][j] = 1;
    if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
        ft_set_position(pos, c, i, j);
    if (c == ' ')
        pos->map.world[i][j] = 8;
}

void map_test(t_pos *pos)
{
    

    pos->map.arr = calloc(pos->map.mH *pos->map.mW, sizeof(int));
    for (int i=0; i < pos->map.mH; i++)
    {
        for(int j = 0; j<pos->map.mW; j++)
        {
            pos->map.arr[i * pos->map.mW + j] = 8;
        }
    }
    free(pos->map.arr);
}
void ft_map(t_pos *pos)
{
    int i;
    int j;
    int x;

    i = -1;
    x = 0;
    map_test(pos);
    pos->map.world = (int **)malloc(pos->map.mH * sizeof(int*));
    while (i++ < pos->map.mW)
    {
        j = -1;
        pos->map.world[i] = (int *)malloc(pos->map.mW * sizeof(int));
        while (j++ < pos->map.mW)
        {
            pos->map.world[i][j] = 0;
            if (pos->map.map[x] != '\n' && pos->map.map[x] != '\0')
            {
                ft_set_map(pos, pos->map.map[x], i, j);
                x++;
            }
            else
                pos->map.world[i][j] = 8;
        }
        x++;
    }
    ft_check_map(pos);
}

void    ft_read_map(char *line, t_pos *pos)
{
    char *aux;

    if (ft_strlen(line) > pos->map.mW)
        pos->map.mW = ft_strlen(line);
    pos->map.mH++;
    aux = pos->map.map;
    pos->map.map = ft_strjoin_newline(pos->map.map, line);
    free(aux);
}

void    ft_check_next_line(t_pos *pos, char *line)
{
    if (ft_strchr(line, 'N') && ft_strchr(line, 'O'))
        ft_load_texture(pos, line, 0);
    else if (ft_strchr(line, 'S') && ft_strchr(line, 'O'))
        ft_load_texture(pos, line, 1);
    else if (ft_strchr(line, 'E') && ft_strchr(line, 'A'))
        ft_load_texture(pos, line, 2);
    else if (ft_strchr(line, 'W') && ft_strchr(line, 'E'))
        ft_load_texture(pos, line, 3);
    else if (ft_strchr(line, 'F'))
        ft_rgb(0, pos, line);
    else if (ft_strchr(line, 'C'))
        ft_rgb(1, pos, line);
    else if (ft_strchrs(line, "10") && !ft_strchrs(line, "FCR./"))
        ft_read_map(line, pos);
    else if (!ft_line_is_space(line) && ft_strlen(line) != 0)
        exit_error(pos);
}

void    ft_read_file(t_pos *pos, char **av)
{
    int		fd;
	char    *line;

    pos->map.map = ft_strdup("");

    if (!(fd = open(av[1], O_RDONLY)))
        exit_error(pos);

	while (get_next_line(fd, &line) > 0)
	{
        ft_check_next_line(pos, line);
        free(line);
	}
    close(fd);
    ft_read_map(line, pos);
    free(line);
	ft_map(pos);
    free(pos->map.map);
}
