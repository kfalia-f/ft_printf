/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:43:04 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/08 19:19:18 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			count;

	va_start (argptr, format);
	count = ft_parser(format, argptr);
	va_end (argptr);
	return (count);
}
