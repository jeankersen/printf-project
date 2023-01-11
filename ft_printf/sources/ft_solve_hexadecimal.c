/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:12:27 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/04 14:26:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	to_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

// 64bits max number is 16 char to write it in base 16
void	ft_printf_hexadecimal(t_arg *arg)
{
	unsigned int	nbr;
	char			str[16 + 1];
	int				len;

	nbr = va_arg(arg->args, unsigned int);
	ft_bzero(str, 17);
	ft_itoa_hex(str, nbr);
	len = ft_strlen(str);
	if (arg->arg_type == 'X')
		to_uppercase(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	arg->written = len;
	return ;
}
