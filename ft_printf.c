/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:00:55 by ialvarez          #+#    #+#             */
/*   Updated: 2021/09/01 21:27:55 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
    va_list	a_list;
	t_flags	*fl;
    int		ret;

	fl = ft_calloc(1, sizeof(t_flags));
	fl->dotcom = -1;
	if (!fl)
		return (-1);
    va_start(a_list, format);
//	va_arg
    ret = ft_vsprintf(format, a_list, fl);
	free(fl);
    va_end(a_list);
    return(ret);
}

int main ()
{
  // int r = 0;
  // int i = -555;
   int j = 325456;
   //char *c = "cach";
   int ret = 0;
   //ret  = ft__printf("%dhola%d%d%s-->%cALON",r,i,j,x,c);
   ret  = ft_printf("Fake [%x]\n", j);
   printf("Original [%x]\n", j);
   //system("leaks printf");
}
