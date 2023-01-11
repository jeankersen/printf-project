/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:09:26 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/07 10:57:41 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	const char	*format;
	int			cursor;
	int			cursor_arg;
	char		arg_type;
	int			written;
	va_list		args;
	int			part[4];
}	t_arg;

int		ft_printf(const char *format, ...);
void	ft_parse_arg_type(t_arg *arg);
void	ft_write_arg_data(t_arg *arg);
void	ft_printf_char(t_arg *arg);
void	ft_printf_str(t_arg *arg);
void	ft_printf_pointer(t_arg *arg);
void	ft_printf_int(t_arg *arg);
void	ft_printf_unsigned(t_arg *arg);
void	ft_printf_hexadecimal(t_arg *arg);
void	ft_printf_pourcentage(t_arg *arg);

void	ft_itoa_hex(char *str, unsigned long long nbr);
char	*ft_itoa_printf(long n);
#endif
