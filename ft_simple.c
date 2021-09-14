/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:45 by ialvarez          #+#    #+#             */
/*   Updated: 2021/09/14 16:25:58 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_dec(const char *format, va_list a_list, t_flags *fl)
{
	if (format[fl->o] == 'd' || format[fl->o] == 'i')
	{
		fl->some = ft_itoa(va_arg(a_list, int));
		fl->str = fl->some;
	}
	else if (format[fl->o] == 'u')
	{
		fl->some = ft_itoa_base((unsigned int)va_arg(a_list, int), 10);
		fl->str = fl->some;
	}
}

static void	ft_specifier_triple(const char *format, va_list a_list, t_flags *fl)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	if (format[fl->o] == 'X')
	{
		fl->some = ft_itoa_base_x((unsigned int)va_arg(a_list, void *), 16);
		fl->str = fl->some;
	}
	else if (format[fl->o] == 'x')
	{
		fl->some = ft_itoa_base((unsigned int)va_arg(a_list, void *), 16);
		fl->str = fl->some;
	}
	else if (format[fl->o] == 'p')
	{
		fl->some = ft_itoa_base((unsigned long long)va_arg(a_list, void *), 16);
		fl->str = (char *)malloc((ft_strlen(fl->some) + 2) * sizeof(char));
		fl->str[0] = '0';
		fl->str[1] = 'x';
		while (fl->some[i] != '\0')
			fl->str[j++] = fl->some[i++];
		free(fl->str);
	}
}
static void		ft_putstr_fda(char *s, int fd, t_flags *fl)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	fl->ret = fl->ret + ft_strlen(s);
}

char	*ft_simple(const char *format, va_list a_list, t_flags *fl)
{
	if (format[fl->o] == 'c')
	{
		fl->some = ft_char2str(va_arg(a_list, int));
		fl->str = fl->some;
	}
	else if (format[fl->o] == 'u' || format[fl->o] == 'd'
		|| format[fl->o] == 'i')
		ft_dec(format, a_list, fl);
	else if (format[fl->o] == 's')
		fl->str = va_arg(a_list, char *);
	else if (format[fl->o] == '%')
	{
		fl->some = ft_char2str(format[fl->o]);
		fl->str = fl->some;
	}
	else if (format[fl->o] == 'X' || format[fl->o] == 'x'
		|| format[fl->o] == 'p')
		ft_specifier_triple(format, a_list, fl);
	ft_putstr_fda(fl->str, 1, fl);
	free(fl->some);
	return (fl->str);
}
