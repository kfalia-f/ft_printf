/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:18:12 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/31 19:20:55 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_num(double *num)
{
	while (*num + 0.1 >= 1)
		(*num)--;
	if (*num < 0)
		*num *= -1;
}

char	*ft_s2(int len, double num)
{
	int		i;
	char	*s2;

	ft_num(&num);
	s2 = ft_memalloc(len + 1);
	i = 0;
	while (i < len)
	{
		if (num + 0.1 >= 1)
			ft_num(&num);
		num *= 10;
		s2[i++] = '0' + num + 0.1;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_f(char **tmp, va_list list, t_flags *fl)
{
	char	*s1;
	int		len;
	int		i;
	double	num;

	num = va_arg(list, double);
	s1 = ft_strjoinre(ft_itoa(num), ".", 1);
	len = 6;
	i = 0;
	if (fl->bits.len)
		len = fl->bits.len;
	s1 = ft_strjoinre(s1, ft_s2(len, num), 3);
	*tmp = ft_strjoinre(*tmp, s1, 3);
	fl->bits.f = 0;
}

void	ft_persent(char **tmp, t_flags *fl)
{
	char	*res;

	res = ft_strdup("%");
	if (fl->bits.num || fl->bits.len)
		res = ft_null(res, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
}
