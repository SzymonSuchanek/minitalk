/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:09:41 by ssuchane          #+#    #+#             */
/*   Updated: 2024/03/23 16:22:42 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		ft_hexa(nbr / 16);
		ft_hexa(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

int	ft_address(unsigned long nbr)
{
	int	count;

	count = 2;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += ft_hexa(nbr);
	return (count);
}

// int	main(void)
// {
// 	unsigned long int	h = 10;
// 	unsigned long int	*address2 = &h;

// 	ft_address(*address2);
// 	return (0);
// }
