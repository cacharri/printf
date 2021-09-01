/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:50:28 by ialvarez          #+#    #+#             */
/*   Updated: 2021/09/01 21:27:52 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_size(unsigned long n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n != 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa_base(unsigned long n, int dh)
{
	int		len;
	char	*num;
	char	*base;

	printf("a");
	base = ft_strdup("0123456789abcdef");
	len = ft_size(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		num[0] = '0';
	while (n != 0)
	{
		len--;
		num[len] = base[n % dh];
		n = n / dh;
	}
	return (num);
}
