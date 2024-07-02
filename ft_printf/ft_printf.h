/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:42:25 by ssuchane          #+#    #+#             */
/*   Updated: 2024/03/25 16:17:05 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *placeholders, ...);
size_t	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putchar(int c);
int		ft_address(unsigned long nbr);
int		ft_print_char(char c);
int		ft_printhex(unsigned int nbr, const char placeholders);
int		ft_print_uint(unsigned int nbr);
int		ft_print_int(int nbr);
int		ft_edge_int(int nbr);

#endif