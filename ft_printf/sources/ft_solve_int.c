/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:12:31 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/04 15:14:03 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_int(t_arg *arg)
{
	int		sign;
	char	*str;
	int		len;
	long	nbr;

	nbr = (long)va_arg(arg->args, int);
	sign = 1;
	if (nbr < 0)
		sign = -1;
	str = ft_itoa_printf((nbr * (long)sign));
	len = ft_strlen(str);
	if (sign == -1)
	{
		len++;
		write(STDOUT_FILENO, "-", 1);
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	arg->written = len;
	free(str);
	return ;
}
