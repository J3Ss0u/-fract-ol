CC = cc

NAME= fractol

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = /usr/local

SRCS = fractol.c \
	julia.c mandelbrot.c burning.c color_shift.c move_julia.c mlx_protect.c \
	ft_printf.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_putptr.c \
	ft_putunsigned.c ft_putx.c

OBJS = $(SRCS:.c=.o)

INCLUDES = fractol.h ft_printf.h\

MLX = -I$(MLX_DIR)/include -L$(MLX_DIR)/lib  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS)  -c $< -o $@ 

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $@


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
