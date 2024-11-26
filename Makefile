Library    = ft_printf
OUTN       = $(Library).a

files      := ft_handle.c ft_hex.c ft_hex_up.c ft_numbers.c ft_printchar.c ft_printf.c ft_strlen.c
OFILES     = $(files:.c=.o)

Compiler   = gcc
CmpFlags   = -Wall -Wextra -Werror

NAME       = $(OUTN)

%.o: %.c
	$(Compiler) $(CmpFlags) -c $< -o $@

$(NAME): $(OFILES)
	ar -rc $(OUTN) $(OFILES)
	ranlib $(OUTN)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(OUTN)

re: fclean all

.PHONY: all clean fclean re

