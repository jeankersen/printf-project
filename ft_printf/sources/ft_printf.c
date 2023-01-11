/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:11:48 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/12 12:48:41 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// access to static functions is restricted to the file where they are declared
// so the reuse of the same function name in other files is not allowed

// ft_parse_format...checking total number of prototype found
// is_arg is the number of prototype to be returned
static int	ft_parse_format(t_arg *arg)
{
	int	is_arg;

	is_arg = 1;
	arg->written = 0;
	arg->cursor++;
	ft_bzero(arg->part, 4);
	if (arg->format[arg->cursor] != 0)
		ft_parse_arg_type(arg);
	if (arg->part[3])
		ft_write_arg_data(arg);
	else
		is_arg = 0;
	return (is_arg);
}

// ft_write_arg...checking for prototype
// then return number that will be sent to ft_loop_format
static int	ft_write_arg(t_arg *arg)
{
	int	written;

	arg->cursor_arg = arg->cursor;
	arg->written = 0;
	written = 0;
	if (ft_parse_format(arg))
		written += arg->written;
	else
	{
		while ((arg->cursor_arg) < (arg->cursor))
		{
			ft_putchar_fd(arg->format[arg->cursor_arg], STDOUT_FILENO);
			arg->cursor_arg++;
			written++;
		}
	}
	return (written);
}

// ft_loop_format check every element of the format
// by looping through the format that contain the string
static int	ft_loop_format(t_arg *arg)
{
	int	written;

	written = 0;
	while (arg->format[arg->cursor] != 0)
	{
		if ((arg->format[arg->cursor] == '%')
			&& (arg->format[arg->cursor + 1] != '%'))
			written += ft_write_arg(arg);
		else if ((arg->format[arg->cursor] == '%')
			&& (arg->format[arg->cursor + 1] == '%'))
		{
			ft_putchar_fd(arg->format[arg->cursor + 1], STDOUT_FILENO);
			written++;
			arg->cursor += 2;
		}
		else
		{
			ft_putchar_fd(arg->format[arg->cursor], STDOUT_FILENO);
			written++;
			arg->cursor++;
		}
	}
	return (written);
}

// total_written is the number that will be written by the function
// t_arg arg ...put my sructure here for easy access to all variable
// va_start : initialize my pointer using the last fixed parameter
// arg.format : associate the last parameter on my structure
int	ft_printf(const char *format, ...)
{
	int		total_written;
	t_arg	arg;

	va_start(arg.args, format);
	total_written = 0;
	arg.format = format;
	arg.cursor = 0;
	total_written = ft_loop_format(&arg);
	va_end(arg.args);
	if (total_written < 0)
		return (0);
	return (total_written);
}
