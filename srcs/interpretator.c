/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:32:47 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/08 20:08:13 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_write(const char *str, int *i)
{
	ft_putchar(str[*i]);
	return (0);
}

int		ft_interpretator(const char *str, int *i, va_list list)
{
	if (!str[*i])
		return (1);
	if (!ft_valid(str[*i]))
		return (ft_write(str, i));
	(void)list;
	return (0);
}
