/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diou.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:11:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/23 19:47:28 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_d(char **tmp, va_list list, t_flags *fl)
{
	unsigned int	unum;
	int				num;
	char			*res;

	num = va_arg(list, int);
	if (num > 0 && !fl->bits.u)
		ft_plus_space(tmp, fl);
	if (fl->bits.u && num < 0)
	{
		unum = 4294967295 + num + 1;
		res = ft_itoa_unsig(unum);
	}
	else
		res = ft_itoa(num);
	if (fl->bits.null || fl->bits.num != 0)
		res = ft_null(res, fl, ft_lon(fl, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
}

void	ft_o(char **tmp, va_list list, t_flags *fl)
{
	unsigned int		n;
	char				str[10000];
	int					i;
	char				*res;

	i = 0;
	n = va_arg(list, unsigned int);
	if (fl->bits.hesh)
		ft_hesh(tmp, fl);
	while (n > 7)
	{
		str[i++] = '0' + n % 8;
		n /= 8;
	}
	str[i] = '0' + n;
	str[i + 1] = '\0';
	res = ft_memalloc(i + 2);
	n = 0;
	while (str[i])
		res[n++] = str[i--];
	res[n] = '\0';
	if (fl->bits.null || fl->bits.num != 0)
		res = ft_null(res, fl, ft_lon(fl, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
	fl->bits.o = 0;
}

void	ft_diou(char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.d || fl->bits.i || fl->bits.u)
		ft_d(tmp, list, fl);
	else if (fl->bits.o)
		ft_o(tmp, list, fl);
	fl->value = 0;
}
