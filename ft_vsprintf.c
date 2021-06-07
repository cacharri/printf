/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:47:46 by ialvarez          #+#    #+#             */
/*   Updated: 2021/06/07 19:34:06 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
void	ft_flags_flying(const char *format, va_list arg, t_flags *flags)
{
	int o;

	o = 0;
	while (format[o])
	{	
	}
}*/

int ft_vsprintf(const char *format, va_list arg)
{
	char	*print;
	char	*tmp;
	int o = 0;
	int		len;
   //char *spc;
   //spc = 0;
	print = ft_strdup("");
	while (format[o])
	{
		if (format[o] == '%')
		{
			++o;
			if (format[o] == 'c' || format[o] == 's' || format[o] == 'd' || format[o] == 37)
				tmp = ft_simple(format, arg, print);
			free(print);
		}
		o++;
	}
	ft_putstr_fd(tmp, 1);
	len = ft_strlen(tmp);
	free(tmp);
   	return(len); 
}
