/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:44:10 by lprieri       #+#    #+#                 */
/*   Updated: 2023/12/06 16:51:42 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	nbr;

	if (ptr == NULL)
		len = ft_putstr("(nil)");
	else
	{
		nbr = (unsigned long long) ptr;
		len = ft_putstr("0x");
		len += ft_puthex_ptr(nbr, "0123456789abcdef");
	}
	return (len);
}

int	ft_puthex_ptr(unsigned long long nbr, char *base)
{
	unsigned long long	n;
	int					len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		n = -nbr;
	}
	else
		n = nbr;
	if (n < 16 && n >= 0)
	{
		len += ft_putchar(base[n]);
	}
	else
	{
		len += ft_puthex_ptr(n / 16, base);
		len += ft_putchar(base[n % 16]);
	}
	return (len);
}
