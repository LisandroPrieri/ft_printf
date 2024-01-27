/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:44:48 by lprieri       #+#    #+#                 */
/*   Updated: 2024/01/22 11:44:24 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	n;
	int		len;

	n = nbr;
	len = 0;
	if (n < 0)
	{
		n = -n;
		len += ft_putchar('-');
	}
	if (n == 0)
		len += ft_putchar('0');
	if (n > 0 && n < 10)
		len += ft_putchar(n + '0');
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar((n % 10) + '0');
	}
	return (len);
}
