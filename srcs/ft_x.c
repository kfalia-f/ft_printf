/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:14:54 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/28 21:05:08 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_x(char **tmp, va_list list, t_flags *fl)
{
	char			*res;
	unsigned int	n;

	n = va_arg(list, unsigned int);
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
	if (fl->bits.null || fl->bits.num)
		res = ft_null(res, fl, ft_lon(fl, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
	fl->value = 0;
}
