/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:07:16 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/10 20:35:52 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_c(char **tmp, va_list list, t_flags *fl)
{
	char	dst[2];

	dst[0] = va_arg(list, int);
	dst[1] = '\0';
	*tmp = ft_strjoinre(*tmp, dst);
	fl->bits.c = 0;
}

void	ft_s(char **tmp, va_list list, t_flags *fl)
{
	char	*dst;

	dst = ft_strdup(va_arg(list, char *));
	*tmp = ft_strjoinre(*tmp, dst);
	ft_strdel(&dst);
	fl->bits.s = 0;
}
/*
void	ft_p(char **tmp, va_list list, t_flags *fl)
{

}
*/
void	ft_csp(char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.c)
		ft_c(tmp, list, fl);
	else if (fl->bits.s)
		ft_s(tmp, list, fl);
//	else
//		ft_p(tmp, list, fl);
}
