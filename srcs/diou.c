/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diou.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:11:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/31 23:41:22 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	ft_what_sign(t_flags *fl, long long num)
{
	if (num < 0)
		return ('-');
	if (fl->bits.plus)
		return ('+');
	return (' ');
}

void	ft_sign(char **res, long long num, t_flags *fl)
{
	int		i;
	int		flag;
	char	c;

	i = 0;
	flag = 0;
	c = ft_what_sign(fl, num);
	while ((*res)[i] && (*res)[i] == ' ' && (flag = 1))
		i++;
//	printf ("%lld, %s\n", num, *res);
	if (num < 0 && fl->bits.num - fl->bits.len == 1 && fl->bits.len == (int)ft_strlen(ft_itoa_long(num)))
	{
		while ((*res)[i] && (*res)[i] != '-')
			i++;
		(*res)[i] = '0';
		(*res)[i - 1] = '-';
		return ;
	}
	if (flag)
		(*res)[i - 1] = c;
	i = 0;
	if (num < 0 && (flag || (*res)[0] == '0'))
	{
		while ((*res)[i] && (*res)[i] != '-')
			i++;
		(*res)[i] = (*res)[i - 1];
	}
	if (num < 0 && (*res)[0] == '0' && fl->bits.len < fl->bits.num)
		(*res)[0] = c;
	else if (!flag && num < 0 && (*res)[0] == '0' && fl->bits.len > fl->bits.num)
		*res = ft_strjoinre(&c, *res, 2);
	if (fl->bits.minus && (fl->bits.space || fl->bits.plus))
	{
		while ((*res)[i])
			i++;
		(*res)[i - 1] = '\0';
		*res = ft_strjoinre(&c, *res, 2);
		return ;
	}
	if (!flag && (fl->bits.space || fl->bits.plus) && c != '-')
	{
		if ((*res)[0] == '0' && num != 0)
			(*res)[0] = c;
		else
			*res = ft_strjoinre(&c, *res, 2);
	}
}

void	ft_d(char **tmp, va_list list, t_flags *fl)
{
	long long			num;
	char				*res;

	num = ft_convers(list, fl);
	if (fl->bits.len == 0 && num == 0)
		res = ft_strdup("");
	else if (fl->bits.l || fl->bits.ll)
		res = ft_itoa_long(num);
	else if (fl->bits.u)
		res = ft_itoa_unsig(num);
	else
		res = ft_itoa(num);
	if (fl->bits.num > 0 || fl->bits.len > 0)
		res = ft_num_form(res, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	ft_sign(&res, num, fl);
	*tmp = ft_strjoinre(*tmp, res, 3);
}

void	ft_o(char **tmp, va_list list, t_flags *fl)
{
	unsigned int		n;
	char				str[10000];
	int					i;
	char				*res;

	i = 0;
	n = va_arg(list, unsigned int);
	while (n > 7)
	{
		str[i++] = '0' + n % 8;
		n /= 8;
	}
	str[i] = '0' + n;
	str[i + 1] = '\0';
	res = ft_memalloc(i + 2);
	n = 0;
	while (str[i])
		res[n++] = str[i--];
	res[n] = '\0';
	if (fl->bits.hesh)
		ft_hesh(&res, fl);
	if (fl->bits.null > 0 || fl->bits.num > 0)
		res = ft_null(res, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
	fl->bits.o = 0;
}

void	ft_diou(char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.d || fl->bits.i || fl->bits.u)
		ft_d(tmp, list, fl);
	else if (fl->bits.o)
		ft_o(tmp, list, fl);
	fl->value = 0;
}
