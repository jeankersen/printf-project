/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:12:21 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/04 14:24:17 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_char(t_arg *arg)
{
	char	c;

	c = va_arg(arg->args, int);
	if (c == 0)
		write(STDOUT_FILENO, "\x00", 1);
	else
		ft_putchar_fd(c, STDOUT_FILENO);
	arg->written = 1;
}
