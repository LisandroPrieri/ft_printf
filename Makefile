# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lprieri <lprieri@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/05 13:25:32 by lprieri       #+#    #+#                  #
#    Updated: 2023/12/06 16:59:50 by lprieri       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c \
		conversions/ft_putchar.c \
		conversions/ft_putstr.c \
		conversions/ft_putptr.c \
		conversions/ft_putnbr.c \
		conversions/ft_putuns.c \
		conversions/ft_puthex.c \
		

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) ft_printf.h
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

exe: re main.c $(NAME)
	@$(CC) $(CFLAGS) -g main.c libftprintf.a && ./a.out | cat -e
	@rm -f $(OBJECTS)
	@rm -f $(NAME)

.PHONY: all clean fclean re exe