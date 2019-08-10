/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:45:32 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/10 20:50:07 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_1st_per(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}
