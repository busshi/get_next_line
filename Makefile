# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 10:25:36 by aldubar           #+#    #+#              #
#    Updated: 2020/11/27 16:41:35 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

BONUS_NAME	=	bonus.out

MULTI_FD_NAME	=	multi_fd.out

SRCS		=	main.c \
			get_next_line.c \
			get_next_line_utils.c \

BONUS_SRCS	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			main_bonus.c

MULTI_FD_SRCS	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			main_multi_fd.c

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)
	
$(NAME):
		$(CC) $(CFLAGS) -D BUFFER_SIZE=32 $(SRCS) -o $(NAME)

bonus:
		$(CC) $(CFLAGS) -D BUFFER_SIZE=32 $(BONUS_SRCS) -o $(BONUS_NAME)
		$(CC) $(CFLAGS) -D BUFFER_SIZE=32 $(MULTI_FD_SRCS) -o $(MULTI_FD_NAME)

clean:
		rm -rf $(NAME) $(BONUS_NAME) $(MULTI_FD_NAME)

fclean:		clean

re:		fclean all

.PHONY:		all re clean fclean bonus
