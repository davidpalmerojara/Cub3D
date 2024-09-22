/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:27:07 by jsoria-f          #+#    #+#             */
/*   Updated: 2021/02/05 16:38:40 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 8
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, int len);
char	*gnl_strjoin(char *s1, char *s2);

#endif
