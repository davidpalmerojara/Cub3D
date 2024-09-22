# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dapalmer <dapalmer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 18:17:10 by dapalmer          #+#    #+#              #
#    Updated: 2021/07/29 08:39:02 by Dapalmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang
CFLAGS	= -Wall -Wextra -I$(INC_DIR)
NAME 	= 	libft.a


SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC	=	ft_bzero.c				\
			ft_atoi.c				\
			ft_itoa.c				\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_tolower.c			\
			ft_toupper.c			\
			ft_calloc.c				\
			ft_memcpy.c				\
			ft_memset.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strlen.c				\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strdup.c				\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_strmapi.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_lstnew.c				\
			ft_lstadd_front.c		\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_printf.c				\
			ft_printf_char.c		\
			ft_printf_flags.c		\
			ft_printf_number.c		\
			ft_printf_ptr.c			\
			ft_printf_types.c		\
			ft_printf_string.c		\
			ft_printf_utils.c		\
			ft_ulltoa.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_swap_int.c			\
			ft_strchrs.c


OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libft.h ft_printf.h get_next_line.h

all		: 	message $(NAME)
			
$(NAME)	:	$(TEST) $(OBJ_DIR) $(OBJS)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo " [OK]"

message:
		@echo -n "[..] Compiling libraries: "

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		@echo -n "."
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean	:
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		: 	fclean all

.PHONY:		all clean fclean re
