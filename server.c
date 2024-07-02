/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:44:07 by ssuchane          #+#    #+#             */
/*   Updated: 2024/07/02 10:40:28 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_char(int pid, int bit)
{
	static int	i = 0;
	static char	c = 0;

	if (i < 8)
	{
		c = c | bit << (7 - i);
		i++;
	}
	if (i == 8)
	{
		if (c == '\0' && pid)
			kill(pid, SIGUSR1);
		g_message.buffer[g_message.index++] = c;
		if (c == '\0')
		{
			write(1, g_message.buffer, g_message.index - 1);
			write(1, "\n", 1);
			g_message.index = 0;
		}
		i = 0;
		c = 0;
	}
}

void	sig_action(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		convert_to_char(info->si_pid, 1);
	else if (signum == SIGUSR2)
		convert_to_char(info->si_pid, 0);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &sig_action;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
