NAME = libutils.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

HEADER = libutils.h

FTIS = alnum alpha ascii count digit in print space spacenl where

FTSKIP = space spacenl char chars

FTLST = add_back add_front clear delone iter last map new size

FTMATH = nbrlen power

FTMEM = bzero calloc memccpy memchr memcmp memcpy memdel memmove memset

FTPUT = char endl nbr str char_fd endl_fd nbr_fd str_fd

FTSTR = chr dup join lcat lcpy len mapi ncmp nstr rchr trim

FTSUB = ft_str/ft_substr ft_str/ft_split

FTTO = tolower toupper atoi itoa

FTGNL = get_next_line

SRC = $(addsuffix .c, $(addprefix ft_is/ft_is, $(FTIS))) \
	$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FTLST))) \
	$(addsuffix .c, $(addprefix ft_math/ft_, $(FTMATH))) \
	$(addsuffix .c, $(addprefix ft_mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix ft_put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix ft_skip/ft_skip_, $(FTSKIP))) \
	$(addsuffix .c, $(addprefix ft_str/ft_str, $(FTSTR)) $(FTSUB)) \
	$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \
	$(addsuffix .c, $(addprefix ft_gnl/, $(FTGNL))) \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re norm
