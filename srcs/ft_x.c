/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:14:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/15 19:32:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pull_res(char *str, int	i)
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

void	ft_x(char **tmp, va_list list, t_flags *fl)
{
	char			str[10000];
	char			*res;
	char			c;
	unsigned int	n;
	int				i;

	n = va_arg(list, unsigned int);
	i = 0;
	c = 'A';
	if (fl->bits.x)
		c = 'a';
	while (n > 15)
	{
		if (n % 16 > 9)
			str[i++] = c + n % 16 - 10;
		else
			str[i++] = '0' + n % 16;
		n /= 16;
	}
	str[i] = '0' + n;
	if (n > 9)
		str[i] = c + n - 10;
	str[i + 1] = '\0';
	res = ft_pull_res(str, i);
	*tmp = ft_strjoin2re(*tmp, res);
	fl->value = 0;
}
