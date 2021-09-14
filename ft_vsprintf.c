/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:47:46 by ialvarez          #+#    #+#             */
/*   Updated: 2021/09/14 16:25:56 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(const char *format, va_list a_list, t_flags *fl)
{
	while (format[fl->o])
	{
		if (format[fl->o] == '%')
		{
			fl->o += 1;
			if (ft_strchr(SPECIFIERS, format[fl->o]))
				ft_simple(format, a_list, fl);
		}
		else
		{
			write(1, &format[fl->o], 1);
			fl->ret += 1;
		}
		fl->o += 1;
	}
	fl->o -= 1;
	return (fl->o);
}
