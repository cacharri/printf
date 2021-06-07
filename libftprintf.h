/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:06:07 by ialvarez          #+#    #+#             */
/*   Updated: 2021/06/07 19:21:04 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_flags{
	int		negation;
	int		zero;
	int		width;
	int		dotcom;
	int		precis;
	int		flag_pre_va;
	int		num_n;
	char	type;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_vsprintf(const char *format, va_list arg);
char	*ft_char2str(char chr);
char	*ft_return(char *src);
char	*ft_simple(const char *format, va_list arg, char *print);

#endif
