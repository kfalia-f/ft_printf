/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:32:47 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/19 17:54:07 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_interpretator(char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.c || fl->bits.s || fl->bits.p)
		ft_csp(tmp, list, fl);
	else if (fl->bits.d || fl->bits.i || fl->bits.o || fl->bits.u)
		ft_diou(tmp, list, fl);
	else if (fl->bits.x || fl->bits.upper_x)
		ft_x(tmp, list, fl);
	else if (fl->bits.f)
		ft_f(tmp, list, fl);
	else if (fl->bits.persent)
		ft_persent(tmp, fl);
	fl->value = 0;
	fl->bits.num = 0;
	fl->bits.len = 0;
	fl->bits.flag = 0;
}
