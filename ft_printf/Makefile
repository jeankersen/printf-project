# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/02 14:10:31 by jvillefr          #+#    #+#              #
#    Updated: 2021/10/02 14:18:40 by jvillefr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = ft_printf.c ft_parse_arg_type.c\
		ft_printf_utils.c ft_printf_itoa.c ft_solve_char.c\
		ft_solve_str.c ft_solve_pointer.c ft_solve_int.c\
		ft_solve_unsigned.c ft_solve_hexadecimal.c

SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objsm
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) re -C ./libft
	@cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS_PREFIXED)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_PREFIXED)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY	: all clean fclean re help
