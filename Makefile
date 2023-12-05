NAME	=	libftprintf.a

SRC	=	print_adress.c \
		print_char.c print_hex.c\
		print_sinteger.c print_string.c \
		print_unsigned.c ft_printf.c \
		ft_putnbr_fd.c ft_putchar_fd.c\
		ft_strlen.c

OBJS = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
