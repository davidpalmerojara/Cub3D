/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:21:22 by dapalmer          #+#    #+#             */
/*   Updated: 2021/07/29 08:41:47 by Dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_line_is_space(char *c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, int n);
char				*ft_strnstr(const char *s, const char *need, int len);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, int n);
void				*ft_memcpy(void *dest, const void *src, int n);
void				*ft_memset(void *s, int c, int n);
void				*ft_memccpy(void *dest, const void *src, int c, int n);
void				*ft_memmove(void *dest, const void *src, int n);
void				*ft_memchr(const void *s, int c, int n);
int					ft_memcmp(const void *s1, const void *s2, int n);
void				*ft_calloc(int nmemb, int size);
char				*ft_strdup(const char *s);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
int				ft_strlcat(char *dst, const char *src, int dstsize);
char				*ft_substr(char const *s, unsigned int start, int len);
char				*ft_strjoin(char const *s1, char const *s2);
char 				*ft_strjoin_newline(char const *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_swap_int(int *a, int *b);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
int				ft_strchrs(const char *s, char *c);

#endif
