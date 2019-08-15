/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:32:47 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/15 19:24:07 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_interpretator(const char *str, char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.c || fl->bits.s || fl->bits.p)
		ft_csp(tmp, list, fl);
	else if (fl->bits.d || fl->bits.i || fl->bits.o || fl->bits.u)
		ft_diou(tmp, list, fl);
	else if (fl->bits.x || fl->bits.upper_x)
		ft_x(tmp, list, fl);
	ft_strlen(str);
	fl->value = 0;
}
