/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:00:55 by ialvarez          #+#    #+#             */
/*   Updated: 2021/07/28 21:07:17 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
    va_list	a_list;
	t_flags	*flags;
    int		ret;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (-1);
    va_start(a_list, format);
//	va_arg
    ret = ft_vsprintf(format, a_list, flags);
	free(flags);
    va_end(a_list);
    return(ret);
}

int main ()
{
  // int r = 0;
  // int i = -555;
   int j = 798;
   //char *x = "cach";
   //int ret = 0;
   //char *c = "Bobo";
   //ret  = ft__printf("%dhola%d%d%s-->%cALON",r,i,j,x,c);
   //ret  = ft_printf("%05d\n", j);
   printf("%05d\n", j);
   system("leaks printf");
}
