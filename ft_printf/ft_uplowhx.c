/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplowhx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:51:44 by ssuchane          #+#    #+#             */
/*   Updated: 2024/03/23 17:10:32 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhex(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (ft_print_char('0'));
	else if (nbr >= 16)
	{
		ft_lowhex(nbr / 16);
		ft_lowhex(nbr % 16);
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

int	ft_uphex(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (ft_print_char('0'));
	if (nbr >= 16)
	{
		ft_uphex(nbr / 16);
		ft_uphex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'A');
	}
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

int	ft_printhex(unsigned int nbr, const char placeholders)
{
	if (placeholders == 'x')
		return (ft_lowhex(nbr));
	else if (placeholders == 'X')
		return (ft_uphex(nbr));
	return (0);
}
