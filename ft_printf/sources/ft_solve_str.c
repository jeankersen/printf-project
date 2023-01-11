/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:13:25 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/07 11:04:56 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_str(t_arg *arg)
{
	int		len;
	char	*str;
	char	*null;

	str = va_arg(arg->args, char *);
	len = ft_strlen(str);
	null = "(null)";
	if (!str)
	{
		str = null;
		len = 6;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	arg->written = len;
	return ;
}
