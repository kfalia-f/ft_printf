/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:45:32 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/23 19:45:37 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pull_res(char *str, int i)
{
	int		k;
	char	*res;

	k = 0;
	res = ft_memalloc(i + 2);
	while (str[i])
		res[k++] = str[i--];
	res[k] = '\0';
	return (res);
}

int		ft_lon(t_flags *fl, int flag)
{
	if (flag == 2)
	{
		if (fl->bits.len < fl->bits.num)
			return (fl->bits.len);
		return (fl->bits.num);
	}
	if (fl->bits.len < fl->bits.num)
		return (fl->bits.num);
	return (fl->bits.len);
}

char	*ft_16(unsigned long n, t_flags *fl)
{
	char	str[1000];
	char	*res;
	int		i;
	char	c;

	i = 0;
	c = 'a';
	if (fl->bits.upper_x)
		c = 'A';
	while (n > 15)
	{
		if (n % 16 > 9)
			str[i++] = c + n % 16 - 10;
		else
			str[i++] = '0' + n % 16;
		n /= 16;
	}
	str[i] = n + '0';
	if (n > 9)
		str[i] = c + n - 10;
	res = ft_pull_res(str, i);
	return (res);
}

int		ft_1st_percent(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}
