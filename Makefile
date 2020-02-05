NAME = libutils.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = libutils.h

FTIS = alnum alpha ascii count digit in print space spacenl

FTSKIP = ft_is/ft_skip_space ft_is/ft_skip_spacenl

FTLST = add_back add_front clear delone iter last map new size

FTMEM = bzero calloc memccpy memchr memcmp memcpy memmove memset

FTPUT = char endl nbr str char_fd endl_fd nbr_fd str_fd

FTSTR = chr dup join lcat lcpy len mapi ncmp nstr rchr trim

FTSUB = ft_str/ft_substr ft_str/ft_split

FTTO = tolower toupper atoi itoa

SRC = $(addsuffix .c, $(addprefix ft_is/ft_is, $(FTIS)) $(FTSKIP)) \
	$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FTLST))) \
	$(addsuffix .c, $(addprefix ft_mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix ft_put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix ft_str/ft_str, $(FTSTR)) $(FTSUB)) \
	$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

bonus: $(OBJBONUS)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
