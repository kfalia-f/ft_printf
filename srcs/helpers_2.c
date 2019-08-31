/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:35:17 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/31 23:08:58 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char    *ft_itoa_long(long long int n)
{
	char    s[50];
	char    *res;
	int     neg;
	int     i;
	int     j;

	i = 0;
	j = 0;
	neg = n < 0 ? -1 : 1;
	while (neg * n > 9 || neg * n < 0)
	{
		s[i++] = '0' + neg * (n % 10);
		n = n / 10;
	}
	s[i++] = '0' + neg * n;
	if (neg < 0)
		s[i++] = '-';
	if ((res = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = s[j++];
	return (res);
}

int		ft_mom(int n1, int n2, int flag)
{
	if (flag == 1)
	{
		if (n1 > n2)
			return (n1);
		return (n2);
	}
	else
		if (n1 > n2)
			return (n2);
	return (n1);
}
