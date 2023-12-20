/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 15:17:36 by lprieri       #+#    #+#                 */
/*   Updated: 2023/12/06 16:35:00 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* STRUCTS */

typedef struct s_flags
{
	int	alt_form;
	int	zero_padding;
	int	left_adjusted;
	int	space;
	int	sign;
	int	width;
	int	precision;
}	t_flags;

/* FT_PRINTF */
int	ft_printf(const char *arg, ...);
int	ft_conv_specifier(va_list args, const char c);
int	ft_pos_specifier(va_list args, const char c);

/* UTILS */
int	ft_putstr(const char *str);
int	ft_putchar(const char c);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putuns(unsigned int nbr);
int	ft_puthex_ptr(unsigned long long nbr, char *base);
int	ft_puthex(unsigned int nbr, char *base);

#endif