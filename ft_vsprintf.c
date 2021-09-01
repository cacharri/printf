/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:47:46 by ialvarez          #+#    #+#             */
/*   Updated: 2021/09/01 20:32:26 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
void	ft_zero_write(const char *format, va_list arg)
{
	int	p;

	p = (*format + 1) - 48;
	write(1, "0", p - ft_strlen(ft_char2str(arg)));
}*/
/*
void	ft_flags_zero(const char *format, t_flags *flags, va_list arg)
{
	int p;

	//printf("hola");
	p = (*format + 1) - 48;
	if ((flags->zero = 1))
	{
		ft_bzero((void *)format, p - ft_strlen((const char *)arg));
	}
}*/
/*
void	ft_dot_search(t_flags *fl, const char *format)
{

}

void	ft_check_with(const char *format, t_flags *fl)
{
	char	*num;

	while (*format && ft_isdigit(format[fl->o]))
	{
		fl->o += 1;
		num = (char *)format;
		fl->o += 1;
	}
}*/

void	ft_flags_flying(const char *format, t_flags *fl)
{
	while (format[fl->o] && !ft_strchr(SPECIFIERS, format[fl->o]))
	{
		if (format[fl->o] == '0')
			fl->zero = 1;
		else if (format[fl->o] == '-')
			fl->negation = 1;
		else if (format[fl->o] == '.')
			// hacer funcion guaje
			//ft_dot_search(fl, );
			fl->dotcom = 0;
		/*else if (format[fl->o] == '*')
			fl->width = 1;*/
		else if (ft_isdigit(format[fl->o]))
		{
			while (ft_isdigit(format[fl->o]))
			{
				fl->numfl =ft_atoi((char *)format);
				fl->o += 1;
			}
			fl->o -= 1;
		}
		fl->o += 1;
	}
	if (fl->zero == 1 && fl->negation == 1)
		fl->zero = 0;
	if (fl->zero == 1 && fl->dotcom ==1)
		fl->zero = 0;
}

int ft_vsprintf(const char *format, va_list a_list, t_flags *fl)
{
//	char	*tmp;
   //char *spc;
   //spc = 0;
	fl->o = 0;
	while (format[fl->o])
	{
		if (format[fl->o] == '%')
		{
			fl->o += 1;
			if (format[fl->o] && !ft_strchr(SPECIFIERS, format[fl->o]))
				ft_flags_flying(format, fl);
			else if (ft_strchr(SPECIFIERS, format[fl->o]))
			{
				//printf("susmuertos %c\n", format[fl->o]);
				ft_simple(format, a_list, fl);
			//	printf("susmuertos %s\n", tmp);
			}
		}
		else
			write(1, &format[fl->o], 1);
		fl->o += 1;
	}
	fl->o -= 1;
	return(fl->o); 
}

