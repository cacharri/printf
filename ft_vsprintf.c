/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:47:46 by ialvarez          #+#    #+#             */
/*   Updated: 2021/07/28 21:07:18 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_flags(t_flags *flags)
{
	if (flags->zero == 1 && flags->negation == 1)
		flags->zero = 0;
	if (flags->zero == 1 && flags->dotcom ==1)
		flags->zero = 0;
}

void	ft_flags_zero(const char *format, t_flags *flags, va_list arg)
{
	int p;

	//printf("hola");
	p = (*format + 1) - 48;
	if ((flags->zero = 1))
	{
		ft_bzero((void *)format, p - ft_strlen(arg));
	}
}

void	ft_flags_flying(const char format, t_flags *flags)
{
	if (format == '0')
		flags->zero = 1;
	if (format == '-')
		flags->negation = 1;
	if (format == '.')
		flags->dotcom = 1;
	if (format == '*')
		flags->width = 1;
}
int ft_vsprintf(const char *format, va_list arg, t_flags *flags)
{
	static	char	*print;
	char	*tmp;
	int o = 0;
	int		len;
	int		zerolen;
	int		dotbef;
	int		dotafter;
   //char *spc;
   //spc = 0;
	print = ft_strdup("");
	while (format[o])
	{
		if (format[o] == '%')
		{
			o++;
			if (ft_strchr(SPECIFIERS, format[o]))
				tmp = ft_simple(format, arg, print);
			else
			{
				while (!ft_strchr(SPECIFIERS, format[o]))
				{
					ft_flags_flying(format[o], flags);
					if (ft_strchr(format, 0))
					{
						//printf("hola");
						++o;
						zerolen = format[o] - 48;
						ft_flags_zero(format, flags, arg);
						//printf("%d\n", zerolen);
					}
					if (ft_strchr(format, '.'))
					{
						dotbef = format[--o] - 48;
						++o;
						dotafter = format[++o] - 48;
					}/*
					if (ft_strchr(format, '*'))
					{
						
					}*/
					o++;
					
				//	ft_flags_zero(format[o], flags);
				//	o++;
				}
				ft_check_flags(flags);
			}
			free(print);
		}
		o++;
	}
	ft_putstr_fd(tmp, 1);
	len = ft_strlen(tmp);
//	ft_flags_zero(format, flags, arg);
	free(tmp);
   	return(len); 
}
