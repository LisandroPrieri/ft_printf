# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lprieri <lprieri@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/05 13:25:32 by lprieri       #+#    #+#                  #
#    Updated: 2024/01/27 12:37:13 by lisandro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/ft_printf.c \
		srcs/conversions/ft_putchar_printf.c \
		srcs/conversions/ft_putstr_printf.c \
		srcs/conversions/ft_putptr_printf.c \
		srcs/conversions/ft_putnbr_printf.c \
		srcs/conversions/ft_putuns_printf.c \
		srcs/conversions/ft_puthex_printf.c \
		

OBJ = $(SRC:srcs/%.c=objs/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC) ft_printf.h Makefile
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(@:objs/%.o=srcs/%.c) -o $@

clean:
	@-rm -rf objs

fclean: clean
	@-rm -rf $(NAME)

re: fclean all

exe: fclean re main.c $(NAME)
	@$(CC) $(CFLAGS) -g main.c libftprintf.a && ./a.out | cat -e

.PHONY: all clean fclean re exe