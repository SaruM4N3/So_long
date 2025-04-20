# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 19:44:37 by sarunomane        #+#    #+#              #
#    Updated: 2025/04/20 13:53:25 by zsonie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

ADDFLAGS =
CFLAGS = -Wall -Wextra -Werror -MMD -g -mavx2 $(ADDFLAGS) -I $(INC_DIR) -I libft/headers -I minilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lbsd -lmlx -lXext -lX11 -lm -lz
SOLONG_SRCS =	main.c\
				event.c\
				move.c\
				player.c\
				render.c\
				map.c\
				error.c \
				my_mlx/draw.c

OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SOLONG_SRCS)}

DEPS= ${patsubst %.c,$(DIR_OBJ)%.d, $(SOLONG_SRCS)}
-include $(DEPS)

.SILENT:

.PHONY: all
all:
	$(MAKE) -j --no-print-directory ADDFLAGS="-O3" SOLONG_SRCS="$(SOLONG_SRCS)" $(NAME)

.PHONY: debug
debug:
	$(MAKE) -j --no-print-directory ADDFLAGS="-O0 -g3 -D DEBUG=1" SOLONG_SRCS="$(SOLONG_SRCS)" $(NAME)

.PHONY: bonus
bonus:
	$(MAKE) --no-print-directory ADDFLAGS="-O3" SOLONG_SRCS="$(SRCS_BONUS)"

%/:
	mkdir -p $@

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	@echo "$(GREEN)Compiling $*.c $(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Make libft $(RESET)"
	$(MAKE) -s -j -C ./libft

$(MLX):
	$(MAKE) -s -j -C ./minilibx-linux

$(NAME): $(MLX) $(LIBFT) $(DIR_OBJ) $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

.PHONY: clean
clean:
	@$(MAKE) -j clean --no-print-directory -C ./minilibx-linux
	@$(MAKE) -j clean --no-print-directory -C ./libft
	@rm -rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) -j fclean --no-print-directory -C ./libft
	@rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) -j --no-print-directory fclean
	$(MAKE) --no-print-directory all

.DEFAULT_GOAL = all
# COLORS
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
RESET  = \033[0m
