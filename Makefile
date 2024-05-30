NAME = libftprintf.a
CC = cc
SRC = ./srcs
HEADER = ./headers
FLAGS = -Wall -Werro -Wextra
OFILES = $(CFILES:.c=.o)
CFILES = main.c ft_printf.c
RM = rm -f

all: $(NAME)
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER)
clean:
	$(RM) $(OFILES)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
