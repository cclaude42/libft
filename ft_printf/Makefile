NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ../includes/

HEADER = ft_printf.h

SRC = ft_printf.c \
	ft_printf_flagger.c \
	ft_printf_branch_csp.c \
	ft_printf_branch_duxo.c \
	ft_printf_put_c.c \
	ft_printf_put_s.c \
	ft_printf_put_p.c \
	ft_printf_put_du.c \
	ft_printf_put_x.c \
	ft_printf_put_o.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	@echo "\033[0;32mGenerating obj..."
	$(CC) -c $< $(CFLAGS)
	@echo "\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
