/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:11:21 by ssuchane          #+#    #+#             */
/*   Updated: 2024/03/23 16:53:49 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0 || nbr == -2147483648)
		return (ft_edge_int(nbr));
	else if (nbr >= 10)
	{
		ft_print_int(nbr / 10);
		ft_print_int(nbr % 10);
	}
	else if (nbr < 0)
	{
		ft_print_char('-');
		ft_print_int(-nbr);
		len++;
	}
	else if (nbr <= 9)
		ft_putchar(nbr + '0');
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

int	ft_edge_int(int nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
}
