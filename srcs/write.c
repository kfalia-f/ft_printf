/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:50:52 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/02 17:40:11 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_write(char *str, t_flags *fl)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == fl->bits.c_flag)
		{
			write(1, "\0", 1);
			fl->bits.res++;
		}
		write(1, &(str[i]), 1);
		i++;
	}
	if (i == fl->bits.c_flag)
	{
		write(1, "\0", 1);
		fl->bits.res++;
	}
}
