/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:13:41 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/04 14:40:08 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_unsigned(t_arg *arg)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = (long)va_arg(arg->args, unsigned int);
	str = ft_itoa_printf(nbr);
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	arg->written = len;
	free(str);
	return ;
}
