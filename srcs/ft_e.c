/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:59:19 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 19:09:23 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_ecsp(unsigned long long n)
{
	printf("%llu", n);
	return (NULL);
}

void	ft_e(char **tmp, va_list list, t_flags *fl)
{
	unsigned long long	n;
	char				*res;

	n = va_arg(list, unsigned long long);
	res = ft_ecsp(n);
	*tmp = ft_strjoinre(*tmp, "", 1);
	fl->bits.e = 0;
}
