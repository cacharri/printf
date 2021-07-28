/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:45 by ialvarez          #+#    #+#             */
/*   Updated: 2021/07/28 21:07:20 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

char	*ft_simple(const char *format, va_list arg, char *print)
{
	int		total;
	int		i;
	char	*str;

	i = 0;
	total = ft_strlen(format);
	while (i < total)
	{
		if (ft_strchr(format, 'd') || ft_strchr(format, 's'))/*ormat[i] != 37 && (format[i + 1] != 'd' || format[i + 1] != 's'))*/
		{
			str = ft_char2str(format[i]);
			print = ft_strjoin_free(print, ft_char2str(format[i]));
			free(str);
		}
		if (format[i] == 37 && format[i + 1] == 'c')
		{
			print = ft_strjoin_free(print, ft_char2str(va_arg(arg, int)));
			i++;
		}
		if (format[i] == 37 && format[i + 1] == 'd')
		{
			str = ft_itoa(va_arg(arg, int));
			print = ft_strjoin_free(print, str);
			free(str);
			i++;
		}
		if (format[i] == 37 && (format[i + 1] == 's' || format[i + 2] == 's'))
		{
			print = ft_strjoin_free(print, ft_return(va_arg(arg, char *)));
			i++;
		}
		if (format[i] == 37 && format[i + 1] == 37)
		{
			str = ft_char2str(format[i]);
			print = ft_strjoin_free(print, str);
			free(str);
		}
		i++;
	}
	return (print);
}
