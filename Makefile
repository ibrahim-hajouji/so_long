NAME = so_long

NAME2 = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./mandatory/check_map.c \
		./mandatory/check_map_utils.c \
		./mandatory/read_file.c \
		./mandatory/read_file_utils.c \
		./mandatory/ft_exit.c \
		./mandatory/mouvements.c \
		./mandatory/image_handling.c \
		./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putstr.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_printf.c \
		./mandatory/so_long.c

SRCSB = ./bonus/check_map_bonus.c \
		./bonus/check_map_utils_bonus.c \
		./bonus/read_file_bonus.c \
		./bonus/read_file_utils_bonus.c \
		./bonus/ft_exit_bonus.c \
		./bonus/mouvements_bonus.c \
		./bonus/mouvements_enemy_bonus.c \
		./bonus/image_handling_bonus.c \
		./bonus/animation_bonus.c \
		./bonus/mouvements_utils_bonus.c \
		./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putstr.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_printf.c \
		./bonus/so_long_bonus.c

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

$(NAME2) : $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(NAME2) $(MLX_FLAGS)

%.o: %.c ./mandatory/so_long.h ./bonus/so_long_bonus.h ./get_next_line/get_next_line.h ./ft_printf/ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : $(NAME2)

clean :
	rm -f $(OBJS) $(OBJSB)

fclean : clean
	rm -f $(NAME) $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus