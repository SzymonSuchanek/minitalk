/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:42:18 by ssuchane          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:52 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conditions(const char placeholders, va_list args)
{
	int	result;

	result = 0;
	if (placeholders == 's')
		result += ft_putstr(va_arg(args, const char *));
	else if (placeholders == 'c')
		result += ft_print_char(va_arg(args, int));
	else if (placeholders == 'd' || placeholders == 'i')
		result += ft_print_int(va_arg(args, unsigned int));
	else if (placeholders == 'p')
		result += ft_address(va_arg(args, unsigned long));
	else if (placeholders == 'x' || placeholders == 'X')
		result += ft_printhex(va_arg(args, unsigned int), placeholders);
	else if (placeholders == 'u')
		result += (ft_print_uint(va_arg(args, unsigned int)));
	else if (placeholders == '%')
		result += ft_print_char('%');
	return (result);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(args, placeholders);
	while (placeholders[i] != '\0')
	{
		if (placeholders[i] == '%')
		{
			i++;
			result += ft_print_conditions(placeholders[i], args);
		}
		else if (placeholders[i] != '%')
		{
			ft_putchar(placeholders[i]);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}

// int	main(void)
// {
// 	char			a[55] = "Simon";
// 	char			b[55] = "done";
// 	unsigned int	og_function;
// 	unsigned int	my_function;

// 	ft_printf("*********************************\n");
// 	ft_printf("*	Test with string	*\n");
// 	ft_printf("*********************************\n");
// 	og_function = printf("My name is %s, well %s ", a, b);
// 	printf("%d\n", og_function);
// 	my_function = ft_printf("My name is %s, well %s ", a, b);
// 	printf("%d\n", my_function);

// 	char			a1[55] = "";
// 	char			b1[55] = "NULL";
// 	unsigned int	og_functiona1;
// 	unsigned int	my_functionb1;

// 	ft_printf("_________________________________\n");
// 	og_functiona1 = printf("My name is %s, well %s ", a1, b1);
// 	printf("%d\n", og_functiona1);
// 	my_functionb1 = ft_printf("My name is %s, well %s ", a1, b1);
// 	printf("%d\n", my_functionb1);

// 	char			a2[55] = "\a";
// 	char			b2[55] = "\b";
// 	unsigned int	og_functiona2;
// 	unsigned int	my_functionb2;

// 	ft_printf("_________________________________\n");
// 	og_functiona2 = printf("My name is %s, well %s ", a2, b2);
// 	printf("%d\n", og_functiona2);
// 	my_functionb2 = ft_printf("My name is %s, well %s ", a2, b2);
// 	printf("%d\n\n\n\n", my_functionb2);

// 	char			c = 'A';
// 	char			d = 'e';
// 	unsigned int	og_function3;
// 	unsigned int	my_function4;

// 	ft_printf("*********************************\n");
// 	ft_printf("*      Test with characters     *\n");
// 	ft_printf("*********************************\n");
// 	og_function3 = printf("My letter is %c, well don%c ", c, d);
// 	printf("%d\n", og_function3);
// 	my_function4 = ft_printf("My letter is %c, well don%c ", c, d);
// 	printf("%d\n", my_function4);
// 	ft_printf("_________________________________\n");

// 	char			c1 = '\a';
// 	char			d1 = '\b';
// 	unsigned int	og_functionc1;
// 	unsigned int	my_functiond1;

// 	og_functionc1 = printf("My letter is %c, well don%c ", c1, d1);
// 	printf("%d\n", og_functionc1);
// 	my_functiond1 = ft_printf("My letter is %c, well don%c ", c1, d1);
// 	printf("%d\n", my_functiond1);
// 	ft_printf("_________________________________\n");

// 	int			e = 64523;
// 	int			f = -42613;
// 	unsigned int	og_function5;
// 	unsigned int	my_function6;

// 	ft_printf("Test with digits and integers\n");
// 	og_function5 = printf("My digit is %d, and %i ", e, f);
// 	printf("%d\n", og_function5);
// 	my_function6 = ft_printf("My digit is %d, and %i ", e, f);
// 	printf("%d\n\n", my_function6);

// 	//int			g = 5;
// 	int			*address1 = NULL;
// 	int			h = 6;
// 	int			*address2 = &h;
// 	unsigned int	og_function7;
// 	unsigned int	my_function8;

// 	ft_printf("Test with address\n");
// 	og_function7 = printf("My pointer address is %p, and %p ",
//	address1, address2);
// 	printf("%d\n", og_function7);
// 	my_function8 = ft_printf("My pointer address is %p, and %p ",
//	address1, address2);
// 	printf("%d\n\n", my_function8);

// 	int			i = 64523;
// 	int			j = -42613;
// 	unsigned int	og_function9;
// 	unsigned int	my_function10;

// 	ft_printf("Test with hexadecimal\n");
// 	og_function9 = printf("My thingie is %x, and %X ", i, j);
// 	printf("%d\n", og_function9);
// 	my_function10 = ft_printf("My thingie is %x, and %X ", i, j);
// 	printf("%d\n\n", my_function10);

// 	ft_printf("Test with no format specifier\n");
// 	ft_printf("%d\n", ft_printf("hello world "));
// 	printf("%d\n\n", printf("hello world "));

// 	unsigned int	k = 4294967295;
// 	unsigned int	l = 3435345221;
// 	unsigned int	og_function11;
// 	unsigned int	my_function12;

// 	ft_printf("Test with hexadecimal\n");
// 	og_function11 = printf("My unsigned int is %u, and %u ", k, l);
// 	printf("%d\n", og_function11);
// 	my_function12 = ft_printf("My unsigned int is %u, and %u ", k, l);
// 	printf("%d\n\n", my_function12);

// 	unsigned int	og_function13;
// 	unsigned int	my_function14;

// 	ft_printf("Test with hexadecimal\n");
// 	og_function13 = printf("My %% is %% ");
// 	printf("%d\n", og_function13);
// 	my_function14 = ft_printf("My %% is %% ");
// 	printf("%d\n\n", my_function14);

// 	return (0);
// }
