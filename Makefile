CFLAGS	= -Wall -Werror -Wextra -g3
CC		= cc $(CFLAGS)
MLX		= -lm  -lXext -lX11 -Lmlx -lmlx

NAME =	so_long
NAME_BONUS = so_long_bonus
LIBFT =	libft/libft.a
SRCS =	ft_check_error.c ft_check_map.c ft_draw_map.c ft_handle_event.c ft_handle_images.c \
		ft_handle_map.c ft_path.c ft_path2.c ft_player_moves.c main.c

SRCS_BONUS = Bonus/b_ft_check_error.c Bonus/b_ft_check_map.c Bonus/b_ft_draw_map.c Bonus/b_ft_handle_event.c Bonus/b_ft_handle_images.c \
		Bonus/b_ft_handle_map.c Bonus/b_ft_path.c Bonus/b_ft_path2.c Bonus/b_ft_handle_trap.c Bonus/b_ft_player_moves.c Bonus/b_ft_trap_moves.c Bonus/b_main.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(LIBFT):
	cd libft && $(MAKE)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY = all clean fclean re