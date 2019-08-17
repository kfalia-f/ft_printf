/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:43:04 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 18:49:46 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	t_flags		fl;
	int			count;

	fl.value = 0;
	va_start(argptr, format);
	count = ft_parser(format, argptr, &fl);
	va_end(argptr);
	return (count);
}
