/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuns.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:45:03 by lprieri       #+#    #+#                 */
/*   Updated: 2023/12/06 16:51:49 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putuns(unsigned int nbr)
{
	int		len;
	char	digit;

	len = 0;
	digit = 0;
	if (nbr == 0)
	{
		write (1, "0", 1);
		len++;
	}
	if (nbr > 0 && nbr < 10)
	{
		digit = nbr + '0';
		write (1, &digit, 1);
		len++;
	}
	if (nbr >= 10)
	{
		len += ft_putuns(nbr / 10);
		digit = (nbr % 10) + '0';
		write (1, &digit, 1);
		len++;
	}
	return (len);
}
