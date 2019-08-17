/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:58:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 18:50:02 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		is_conversion(const char c)
{
	return (ft_strchr("diuoxXfFeEgGaAcsSpn%", c) != NULL);
}

int		is_modifier(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

int		is_flag(const char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

int		is_precision(const char c)
{
	return (ft_strchr("$*.", c) != NULL);
}

int		ft_valid(const char c)
{
	return (is_conversion(c) || is_modifier(c) || is_flag(c) ||
			ft_isdigit(c) || is_precision(c));
}
