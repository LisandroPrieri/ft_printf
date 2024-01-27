# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lprieri <lprieri@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/05 13:25:32 by lprieri       #+#    #+#                  #
#    Updated: 2024/01/22 12:33:20 by lisandro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c \
		src/conversions/ft_putchar.c \
		src/conversions/ft_putstr.c \
		src/conversions/ft_putptr.c \
		src/conversions/ft_putnbr.c \
		src/conversions/ft_putuns.c \
		src/conversions/ft_puthex.c \
		

OBJ = $(SRC:src/%.c=obj/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC) ft_printf.h Makefile
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(@:obj/%.o=src/%.c) -o $@

clean:
	@-rm -rf obj

fclean: clean
	@-rm -rf $(NAME)

re: fclean all

exe: fclean re main.c $(NAME)
	@$(CC) $(CFLAGS) -g main.c libftprintf.a && ./a.out | cat -e

.PHONY: all clean fclean re exe