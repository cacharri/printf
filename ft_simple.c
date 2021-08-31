/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:45 by ialvarez          #+#    #+#             */
/*   Updated: 2021/08/31 21:03:00 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
/*
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}*/

char	*ft_simple(const char *format, va_list a_list, t_flags *fl)
{
	char	*str;
	char	*some;

	str = NULL;
	some = NULL;

	if (format[fl->o] == 'c')
	{
		some = ft_char2str(va_arg(a_list, int));
		str = some;
	}
	else if (format[fl->o] == 'd' || format[fl->o] == 'i')
	{
		some = ft_itoa(va_arg(a_list, int));
		str = some;
	}
	else if (format[fl->o] == 's')
		str = va_arg(a_list, char *);
	else if (format[fl->o] == '%')
	{
		some = ft_char2str(format[fl->o]);
		str = some;
	}
	else if (format[fl->o] == 'u')
	{
		some = ft_itoa(va_arg(a_list, int));
		str = some;
	}
	ft_putstr_fd(str, 1);
	free(some);
	return (str);
}
