/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:49:23 by ialvarez          #+#    #+#             */
/*   Updated: 2021/06/15 17:59:06 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char  *ft_char2str(char chr)
{
	char *str;

	str = malloc(sizeof(char) * 2);
	*str = chr;
	str[1] = '\0';
	return (str);
}
