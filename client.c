/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:44:04 by ssuchane          #+#    #+#             */
/*   Updated: 2024/07/02 10:22:56 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	isneg;

	i = 0;
	result = 0;
	isneg = 1;
	if (nptr[i] == 0)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			isneg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (isneg * result);
}

void	send_message(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (((*str >> i) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			i--;
		}
		str++;
	}
	i = 7;
	while (i-- >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(300);
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Signal received.\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
		{
			ft_printf("Wrong PID!\n");
			return (0);
		}
		str = argv[2];
		send_message(pid, str);
	}
	else
	{
		ft_printf("Error!\n");
	}
}
