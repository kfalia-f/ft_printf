/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:14:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/23 19:47:36 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_x(char **tmp, va_list list, t_flags *fl)
{
	char			str[10000];
	char			*res;
	int				n;

	n = va_arg(list, unsigned int);
	if (fl->bits.hesh)
		ft_hesh(tmp, fl);
	res = ft_16(n, fl);
	if (fl->bits.null || fl->bits.num != 0)
		res = ft_null(res, fl, ft_lon(fl, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
	fl->value = 0;
}
