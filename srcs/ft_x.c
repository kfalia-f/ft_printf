/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:14:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/31 22:50:37 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned long long int	ft_convers(va_list list, t_flags *fl)
{
	if (fl->bits.x || fl->bits.upper_x ||
			fl->bits.u || fl->bits.o)
	{
		if (fl->bits.l)
			return (va_arg(list, unsigned long));
		if (fl->bits.ll)
			return (va_arg(list, unsigned long long));
		if (fl->bits.h)
			return ((unsigned short)va_arg(list, int));
		if (fl->bits.hh)
			return ((unsigned char)va_arg(list, int));
		return (va_arg(list, unsigned int));
	}
	if (fl->bits.l)
		return (va_arg(list, long));
	if (fl->bits.ll)
		return (va_arg(list, long long));
	if (fl->bits.h)
		return ((short)va_arg(list, int));
	if (fl->bits.hh)
		return ((char)va_arg(list, int));
	return (va_arg(list, int));
}

void					ft_x(char **tmp, va_list list, t_flags *fl)
{
	char				*res;
	unsigned long long	n;

	n = ft_convers(list, fl);
	if (n == 0 && fl->bits.len < 0)
	{
		*tmp = ft_strjoinre(*tmp, "0", 1);
		return ;
	}
	else if (n == 0)
		res = ft_strdup("");
	else
		res = ft_16(n, fl);
	if (fl->bits.hesh && n > 0 && !fl->bits.null)
		ft_hesh(&res, fl);
	if (fl->bits.upper_x)
		fl->bits.x = 1;
	if (fl->bits.null || fl->bits.num > 0)
		res = ft_null(res, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
	fl->value = 0;
}
