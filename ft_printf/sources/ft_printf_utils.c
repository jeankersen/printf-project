/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:11:42 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/04 14:53:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_itoa_hex(char *str, unsigned long long nbr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
		str[i++] = '0';
	while (nbr > 0)
	{
		str[i++] = base[(nbr % 16)];
		nbr /= 16;
	}
	str[i] = 0;
	ft_strrev(str);
	return ;
}
