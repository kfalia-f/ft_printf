/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:04:07 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/31 22:49:00 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_plus_space(char **tmp, t_flags *fl)
{
	if (fl->bits.plus)
		*tmp = ft_strjoinre(*tmp, "+", 1);
	else if (fl->bits.space)
		*tmp = ft_strjoinre(*tmp, " ", 1);
}

void	ft_hesh(char **tmp, t_flags *fl)
{
	if (fl->bits.o)
		*tmp = ft_strjoinre("0", *tmp, 2);
	if (fl->bits.x)
		*tmp = ft_strjoinre("0x", *tmp, 2);
	else if (fl->bits.upper_x)
		*tmp = ft_strjoinre("0X", *tmp, 2);
}

char	*ft_minus(char *str, int len, t_flags *fl, int num)
{
	char	c;
	char	*tmp;
	int		i;
	int		k;

	c = ' ';
	if (fl->bits.null)
		c = '0';
	tmp = ft_memalloc(num + 1);
	i = 0;
	while (i < fl->bits.len - len)
		tmp[i++] = '0';
	k = 0;
	if (fl->bits.len > 0)
		while (i < fl->bits.len)
			tmp[i++] = str[k++];
	else
		while (i < len)
			tmp[i++] = str[k++];
	while (i < num)
		tmp[i++] = c;
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);
}

int		ft_shesh(char *tmp, t_flags *fl)
{
	tmp[0] = '0';
	if (fl->bits.x)
		tmp[1] = 'x';
	else if (fl->bits.upper_x)
		tmp[1] = 'X';
	else if (fl->bits.o)
		return (1);
	return (2);
}

char	*ft_null(char *str, t_flags *fl, int num, char c)
{
	int		len;
	int		i;
	int		k;
	char	*tmp;

	/*if (fl->bits.null || num == fl->bits.len)
		c = '0';
	len = ft_strlen(str);
	//printf("len = %d, fl.num = %d, num = %d\n", len, fl->bits.num,  num);
	if ((fl->bits.num < len && fl->bits.len <= 0) || num <= 0)
		return (str);
	if (fl->bits.minus)
		return (ft_minus(str, len, fl, num));
	tmp = ft_memalloc(num + 1);
	i = 0;
	if (fl->bits.hesh && fl->bits.null)
		i = ft_shesh(tmp, fl);
	while (i < num - len)
		tmp[i++] = c;
	if (ft_lon(fl, 2) > len)
		i = num - ft_lon(fl, 2);
	while (i < num - len)
		tmp[i++] = '0';
	len = 0;
	while (i < num)
		tmp[i++] = str[len++];
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);
	*/
	if (fl->bits.null || num == fl->bits.len)
		c = '0';
	len = ft_strlen(str);
	if (fl->bits.s && len == 0 && fl->bits.num <= 0)
		return (str);
	if (num <= 0 || (len > fl->bits.num && fl->bits.len <= 0))
		return (str);
	if (fl->bits.minus && num == fl->bits.num)
		return (ft_minus(str, len, fl, num));
	tmp = ft_memalloc(num + 1);
	i = 0;
	k = 0;
	//printf("len = %d, num = %d, fl->bits.len = %d, fl->bits.num = %d\n", len, num, fl->bits.len, fl->bits.num);
	//while (i < fl->bits.num - len + fl->bits.len && i < num)
	if (fl->bits.plus && c == '0' && str[0] != '-')
		tmp[i++] = '+';
	if (str[0] == '-')
	{
		tmp[i++] = '-';
		k++;
		len--;
	}
	if (num == fl->bits.num)
		while (i < num - len + fl->bits.len && i < num)
			tmp[i++] = c;
	else
		while (i < num - len)
			tmp[i++] = c;
	//while (i < num - len + ft_lon(fl, 2) && i < num)
	//	tmp[i++] = c;
	while (i < num)
		tmp[i++] = str[k++];
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);

}
/*
static inline void	ft_pull(char *str, char c, int *len, int *k)
{
	str[0] = c;
	(*len)--;
	(*k)++;
}

void	ft_put_sign(char **res, char *str, t_flags *fl)
{
	if (str[0] == '-')
		ft_pull(res, '-', &len, &k);
}
*/

char	ft_plus_or_space(t_flags *fl)
{
	if (fl->bits.space)
		return (' ');
	return ('+');
}

char	*ft_rev_num(char *str, t_flags *fl, int num, char c)
{
	int		i;
	int		k;
	char	*res;
	int		len;

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

char	*ft_num_form(char *str, t_flags *fl, int num, char c)
{
	int		len;
	char	*res;
	int		i;
	int		k;

	if (fl->bits.null && fl->bits.len <= 0)
		c = '0';
	len = ft_strlen(str);
	i = 0;
	k = 0;
	//printf ("%d\n", );
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
