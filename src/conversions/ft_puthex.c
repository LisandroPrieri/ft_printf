/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:45:18 by lprieri       #+#    #+#                 */
/*   Updated: 2024/01/22 11:44:21 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_puthex(unsigned int nbr, char *base)
{
	unsigned long long	n;
	int					len;

	n = nbr;
	len = 0;
	if (n < 16)
		len += ft_putchar(base[n]);
	else
	{
		len += ft_puthex(n / 16, base);
		len += ft_putchar(base[n % 16]);
	}
	return (len);
}
