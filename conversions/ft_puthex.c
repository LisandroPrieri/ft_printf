/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:45:18 by lprieri       #+#    #+#                 */
/*   Updated: 2023/12/06 16:51:29 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned int nbr, char *base)
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
		len += ft_puthex(n / 16, base);
		len += ft_putchar(base[n % 16]);
	}
	return (len);
}
