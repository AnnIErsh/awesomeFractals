# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aershova <aershova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 18:09:35 by annaershova       #+#    #+#              #
#    Updated: 2024/05/21 03:28:44 by aershova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_B = fractol_bonus

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = actions.c fractal.c image.c main.c newton.c nova.c \
	render.c window.c ship.c window_zoom.c
SRC_B = actions.c fractal.c image.c main.c newton.c nova.c \
	render.c window.c ship.c window_zoom.c

SRC_D = src
SRC_DB = src_bonus
OBJ_D = obj
OBJ_DB = obj_bonus

OBJ = $(SRC:%.c=$(OBJ_D)/%.o)
OBJ_B = $(SRC_B:%.c=$(OBJ_DB)/%.o)

LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a

all: $(OBJ_D) $(NAME)

bonus: $(OBJ_DB) $(NAME_B)

$(OBJ_D)/%.o: $(SRC_D)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DB)/%.o: $(SRC_DB)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D):
	@mkdir -p $(OBJ_D)
$(OBJ_DB):
	@mkdir -p $(OBJ_DB)
$(LIBFT):
	@make --directory libft/
$(MLX):
	@make --directory mlx/ 
	
$(NAME): $(LIBFT) $(MLX) $(OBJ_D) $(OBJ)
	@$(CC) $(OBJ) $(MLX) $(LIBFT)  -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(NAME_B): $(LIBFT) $(MLX) $(OBJ_DB) $(OBJ_B)
	@$(CC) $(OBJ_B) $(MLX) $(LIBFT)  -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean: 
	rm -rf $(OBJ) $(OBJ_B) $(OBJ_D) $(OBJ_DB) 
	make --directory ./libft fclean

fclean: clean
	rm -f $(NAME)

fclean_b: clean
	rm -f $(NAME_B)

re: fclean all

bonus_re: fclean_b bonus

.PHONY: all clean fclean fclean_b re bonus_re libft bonus
