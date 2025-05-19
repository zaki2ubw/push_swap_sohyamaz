# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 15:55:00 by sohyamaz          #+#    #+#              #
#    Updated: 2025/05/07 19:59:45 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target declaration
NAME	= push_swap
SRCS	= format_char.c \
		  format_number.c \
		  ft_printf.c \
		  main.c \
		  ps_check_val.c \
		  ps_cmd_push.c \
		  ps_cmd_rotates.c \
		  ps_cmd_swap.c \
		  ps_exit.c \
		  ps_find_target.c \
		  ps_init_stracts.c \
		  ps_libft.c \
		  ps_make_list.c \
		  ps_optimization.c \
		  ps_opt_quadruple.c \
		  ps_opt_quintuple.c \
		  ps_opt_triple.c \
		  ps_prepare_stacks.c \
		  ps_prints.c \
		  ps_return_stacks.c \
		  ps_utils.c \
		  push_swap.c

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
OBJS	= $(SRCS:%.c=%.o)

#Declaration of rules

all	: $(NAME)

clean	: 
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

#Pony target declaration
.PHONY	: all re clean fclean

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@
