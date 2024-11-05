NAME=cub3D
CC=gcc

FLAGS=-Wall -Werror -Wextra -g

DIR_SRCS=srcs
DIR_OBJS=objects
SUB_DIR_OBJS=$(DIR_OBJS)/parsing $(DIR_OBJS)/gnl $(DIR_OBJS)/game
DIR_INCS=includes
MLX_LIB = mlx/libmlx.so 
MLX_FLAG = $(MLX_LIB) -lSDL2 -lm

LST_SRCS=main.c init.c utils.c free.c \
			parsing/parse_file.c parsing/parse_map.c parsing/flood_fill.c \
			parsing/utils.c gnl/get_next_line_utils.c gnl/get_next_line.c \
			parsing/player_utils.c parsing/name_utils.c \
			game/game.c game/raycasting.c game/mouse.c \
			game/move.c game/wall_utils.c game/utils.c \
			game/raycasting_utils.c \

LST_OBJS=$(LST_SRCS:.c=.o)
LST_INCS=cub3D.h\
			mlx.h \
			mlx_profile.h \

SRCS=$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS=$(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS=$(addprefix $(DIR_INCS)/, $(LST_INCS))

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@mkdir -p $(SUB_DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_INCS) -c $< -o $@
	@echo -n '.'

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C mlx/ all
	@$(MAKE) -C libft/ all
	@$(CC) $(OBJS) $(FLAGS) $(MLX_FLAG) -o $@ libft/libft.a
	@echo "\n\nCub3D compiled"

clean:
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C mlx/ clean
	@rm -f $(OBJS)
	@rm -rf objects
	@echo "All objects clean"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C mlx/ fclean
	@rm -f $(NAME)
	@echo "And the executable too"

re: fclean all

.PHONY: all fclean clean re