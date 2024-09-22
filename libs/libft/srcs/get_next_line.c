/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoria-f <jsoria-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:23:56 by jsoria-f          #+#    #+#             */
/*   Updated: 2020/07/19 17:49:33 by jsoria-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				newlist_exist(char *copia)
{
	int			i;

	i = 0;
	while (copia[i] != '\0')
	{
		if (copia[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				ret_line(char **copia, char **line, int i)
{
	char		*tmp;

	*line = ft_substr(*copia, 0, i);
	tmp = ft_strdup(*copia + i + 1);
	free(*copia);
	*copia = tmp;
	return (1);
}

int				ret_rest(char **copia, char **line)
{
	int			i;

	i = newlist_exist(*copia);
	if (i >= 0)
		return (ret_line(copia, line, i));
	*line = ft_strdup(*copia);
	free(*copia);
	*copia = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	int			rd_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*copia[4096];

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (!copia[fd])
		copia[fd] = ft_strdup("");
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		copia[fd] = gnl_strjoin(copia[fd], buff);
		i = newlist_exist(copia[fd]);
		if (i >= 0)
			return (ret_line(&copia[fd], line, i));
	}
	if (rd_size < 0)
		return (-1);
	return (ret_rest(&copia[fd], line));
}
