SHELL = bash

CC = clang

SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC = main.c map.c controls.c colors.c textures.c calculate.c draw.c error.c

RM = rm -rf

CFLAGS	= -I$(INC_DIR) -Wall -Werror -Wextra #-fsanitize=address

FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

LIBMLX		= ./libs/minilibx/

LIB		= libmlx.dylib

LIBFT	= ./libs/libft/libft.a

NAME	= cub3D

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = cub3d.h

all:		message $(NAME) message2

message:
		@echo ""
		@echo "                       _____   _    _   ____    ____    _____ " 
		@echo "                      / ____| | |  | | |  _ \  |___ \  |  __ \ "
		@echo "                     | |      | |  | | | |_) |   __) | | |  | |"
		@echo "                     | |      | |  | | |  _ <   |__ <  | |  | |"
		@echo "                     | |____  | |__| | | |_) |  ___) | | |__| |"
		@echo "                      \_____|  \____/  |____/  |____/  |_____/ "
		@echo ""
		@echo "====================================================================================="
		@echo "=================================== By Dapalmer ====================================="
		@echo "====================================================================================="
		@echo ""
		@echo "Cub3D, 2020-2021 cursus, is a project inspired by the world famous game Wolfenstein "
		@echo "considered to be the first FPS ever developed. It's our first look to the ray-casting"
		@echo "technique. The aim is to do a dynamic view in a maze."
		@echo ""
		@echo "====================================================================================="
		@echo ""               

message2:
		@echo ""
		@echo "====================================================================================="
		@echo "====================================== Usage ========================================"
		@echo "====================================================================================="
		@echo ""
		@echo "- Execute: ./cub3D" or "./cub3D map."
		@echo "- You can move around the maze with W A S D."
		@echo "- You can also rotate the view with the directional arrows ← and →."
		@echo "- You can shoot/stab with SPACE and open doors with SHIFT."
		@echo "- To exit the game, press ESC or click the red cross."
		@echo ""
		@echo "====================================== Enjoy:) ======================================"
		

$(NAME):	$(OBJ_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(EXT_LIBS) -o $@ libmlx.dylib $(LIBFT)
			@echo ""
			@echo "                         "
			@echo "\033[32m[OK] Successfully compiled CUB3D.\033[0m"
			
$(MLX):
			@$(MAKE) -s -C /libs/minilibx
			@mv /libs/minilibx/libmlx.dylib .

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
			@$(MAKE) -s -C ./libs/libft
			@$(MAKE) -s -C ./libs/minilibx
			@mv ./libs/minilibx/libmlx.dylib .
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo ""
			@echo "====================================================================================="
			@echo ""
			@echo "[..] Compiling project:   ...................................................... [OK]"
			@echo ""
			@echo "====================================================================================="

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJ_DIR)
			

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) -s fclean -C ./libs/libft
			@$(MAKE) -s clean -C ./libs/minilibx
			rm -rf libmlx.dylib
			rm -rf ./libs/minilibx/libmlx.dylib
			

re:
			@$(MAKE) -s fclean
			@$(MAKE) -s all

.PHONY:		all clean fclean re

