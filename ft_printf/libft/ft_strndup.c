/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:37:08 by jvillefr          #+#    #+#             */
/*   Updated: 2021/10/02 14:37:16 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*heap_p;
	char	*p;

	heap_p = malloc(n + 1);
	if (!heap_p)
		return (0);
	p = heap_p;
	while ((*s1 != 0) && (n--))
		*p++ = *s1++;
	*p = '\0';
	return (heap_p);
}
