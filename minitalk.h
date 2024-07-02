/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:44:08 by ssuchane          #+#    #+#             */
/*   Updated: 2024/07/02 10:39:10 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFER_SIZE 1024

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_message
{
	char	c;
	size_t	i;
	char	buffer[BUFFER_SIZE];
	int		index;
}			t_message;

t_message	g_message = {.index = 0};

#endif