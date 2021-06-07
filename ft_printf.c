/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:00:55 by ialvarez          #+#    #+#             */
/*   Updated: 2021/06/07 19:50:22 by ialvarez         ###   ########.fr       */
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
	free(flags);
    va_start(a_list, format);
//	va_arg
    ret = ft_vsprintf(format, a_list);
    va_end(a_list);
    return(ret);
}

int main ()
{
  // int r = 0;
  // int i = -555;
   int j = 798;
//   char *x = "cach";
   int ret = 0;
   //char *c = "Bobo";
   //ret  = ft__printf("%dhola%d%d%s-->%cALON",r,i,j,x,c);
   ret  = ft_printf("%d\n", j);
   printf("%024d\n", j);
   system("leaks printf");
}
