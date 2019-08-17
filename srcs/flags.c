/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:04:07 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 21:18:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_plus_space(char **tmp, t_flags *fl)
{
	if (fl->bits.plus)
		*tmp = ft_strjoinre(*tmp, "+", 1);
	else if (fl->bits.space)
		*tmp = ft_strjoinre(*tmp, " ", 1);
}

void	ft_hesh(char **tmp, t_flags *fl)
{
	if (fl->bits.o)
		*tmp = ft_strjoinre(*tmp, "0", 1);
	if (fl->bits.x)
		*tmp = ft_strjoinre(*tmp, "0x", 1);
	else if (fl->bits.upper_x)
		*tmp = ft_strjoinre(*tmp, "0X", 1);
}
