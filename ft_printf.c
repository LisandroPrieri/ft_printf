/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 14:31:17 by lprieri       #+#    #+#                 */
/*   Updated: 2023/12/19 16:34:10 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		conv;

	va_start(args, arg);
	i = 0;
	len = 0;
	conv = 0;
	while (arg[i])
	{
		if (arg[i] == '%')
		{
			i++;
			conv = ft_conv_specifier(args, arg[i]);
			if (conv == -1)
				return (-1);
			len += conv;
		}
		else
			len += ft_putchar(arg[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_conv_specifier(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_puthex(va_arg(args, unsigned long), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar('%');
	else
		len = -1;
	return (len);
}
