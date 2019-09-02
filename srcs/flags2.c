/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:41:57 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/02 21:45:11 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char    ft_plus_or_space(t_flags *fl)
{
	if (fl->bits.space)
		return (' ');
	return ('+');
}

char    *ft_rev_num(char *str, t_flags *fl, int num, char c)
{
	int     i;
	int     k;
	char    *res;
	int     len;

	if (fl->bits.null)
		c = '0';
	len = ft_strlen(str);
	i = 0;
	k = 0;
	res = ft_memalloc(num + 1);
	while (i < fl->bits.len - len + k)
		res[i++] = '0';
	while (i < ft_mom(len, fl->bits.len, 1))
		res[i++] = str[k++];
	while (i < num)
		res[i++] = c;
	res[i] = '\0';
	ft_strdel(&str);
	return (res);
}

char    *ft_num_form(char *str, t_flags *fl, int num, char c)
{
	int     len;
	char    *res;
	int     i;
	int     k;

	if (fl->bits.null && fl->bits.len <= 0)
		c = '0';
	len = ft_strlen(str);
	i = 0;
	k = 0;
	if (len > num)
		return (str);
	if (fl->bits.minus)
		return (ft_rev_num(str, fl, num, ' '));
	res = ft_memalloc(num + 1);
	while (i < fl->bits.num - ft_mom(len, fl->bits.len, 1))
		res[i++] = c;
	while (i < num - len)
		res[i++] = '0';
	while (i < num)
		res[i++] = str[k++];
	res[i] = '\0';
	ft_strdel(&str);
	return (res);
}
