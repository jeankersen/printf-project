/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:12:35 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/07 11:18:04 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// 64bits computer, so long long and 16 char to write it in hex
void	ft_printf_pointer(t_arg *arg)
{
	char				str[(16 + 1)];
	int					len;
	unsigned long long	address;
	char				*null;

	address = va_arg(arg->args, unsigned long long);
	ft_bzero(str, 17);
	ft_itoa_hex(str, address);
	len = ft_strlen(str);
	null = "0";
	if (!address)
	{
		ft_strlcpy(str, null, 2);
		len = 1;
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	arg->written = len + 2;
	return ;
}
