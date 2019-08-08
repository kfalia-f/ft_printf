/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:19:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/08 20:13:37 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_parser(const char *str, va_list list)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
		{
			if (str[i] == '%')
			{
				i++;
				res++;
				if (ft_interpretator(str, &i, list))
					continue ;
			}
			else
				ft_putchar(str[i]);
			i++;
		}
	return (res);
}
