# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:11:52 by ssuchane          #+#    #+#              #
#    Updated: 2024/07/01 21:30:01 by ssuchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	server.c \
				client.c
SRCS_BON	= 	server_bonus.c \
				client_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BON	=	$(SRCS_BON:.c=.o)

NAME		=	minitalk
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

FLG			=	-L ft_printf -lftprintf

all: $(NAME)
	@echo "\nminitalk compiled successfully...\n"

$(NAME): library $(OBJS)
	@${CC} ${CFLAGS} server.o $(FLG) -o server
	@${CC} ${CFLAGS} client.o $(FLG) -o client

library:
	@make -s -C ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BON)
	@make clean -s -C ft_printf
	@echo "\nclean completed successfully ...\n"

fclean: clean
	@rm -f client
	@rm -f server
	@rm -f client_bonus
	@rm -f server_bonus
	@make fclean -s -C ft_printf

bonus: fclean library $(OBJS_BON)
	@${CC} ${CFLAGS} server_bonus.o $(FLG) -o server_bonus
	@${CC} ${CFLAGS} client_bonus.o $(FLG) -o client_bonus

re: fclean all