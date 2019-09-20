/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:18:12 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/20 05:13:36 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_num(double *num)
{
	while (*num + 0.1 >= 1)
		(*num)--;
	if (*num < 0)
		*num *= -1;
}

char	*ft_s2(int len, double num, int *up)
{
	int			i;
	char		*s2;
	int			sig;
	long long	k;

	s2 = ft_memalloc(len + 1);
	i = 0;
	sig = num >= 0 ? 1 : -1;
	num = (num - (int)num) * sig;
	while (i++ < len + 1)
		num *= 10;
	k = (long long)(num + 0.1);
	//printf("%f, k = %lld\n", num, k);
	i = 0;
	*up = first_dig(k);
	if (k % 10 > 5)
		k += 10;
	if (*up != first_dig(k))
		*up = first_dig(k) == 1 ? 1 : 0;
	else
		*up = 0;
	k = k / 10;
	while (i < len)
	{
		s2[i++] = k % 10 + 48;
		k /= 10;
	}
	s2 = ft_reverse_str(s2);
	s2[i] = '\0';
	if (len == 0)
	{
		ft_strdel(&s2);
		return (ft_strdup(""));
	}
	return (s2);
}

char	*ft_minu(char *s1, t_flags *fl, int len)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tmp = ft_memalloc(len + 1);
	while (i < len)
		tmp[i++] = s1[k++];
	while (i < fl->bits.num)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	ft_strdel(&s1);
	return (tmp);
}

char	*ft_long(char *s1, t_flags *fl, char c)
{
	int		len;
	int		i;
	int		k;
	char	*tmp;

	if (fl->bits.null)
		c = '0';
	len = ft_strlen(s1);
	if (len >= fl->bits.num)
		return (s1);
	if (fl->bits.minus)
		return (ft_minu(s1, fl, len));
	tmp = ft_memalloc(fl->bits.num + 1);
	i = 0;
	k = 0;
	while (i < fl->bits.num - len)
		tmp[i++] = c;
	while (i < fl->bits.num)
		tmp[i++] = s1[k++];
	tmp[i] = '\0';
	ft_strdel(&s1);
	if (fl->bits.null && ft_strchr(tmp, '-'))
	{
		i = 0;
		while (tmp[i] && tmp[i] != '-')
			i++;
		tmp[i] = '0';
		tmp[0] = '-';
	}
	return (tmp);
}

void	ft_plus_f(char **s1, t_flags *fl)
{
	int		i;
	size_t	len;
	char	c[2];

	if (ft_strchr(*s1, '-'))
		return ;
	i = 0;
	len = ft_strlen(*s1);
	if (fl->bits.plus)
		c[0] = '+';
	else if (fl->bits.space)
		c[0] = ' ';
	c[1] = '\0';
	while ((*s1)[i] && !ft_isdigit((*s1)[i]))
		i++;
	if ((*s1)[i] && i != 0)
		(*s1)[i - 1] = c[0];
	else if (i == 0 && (!fl->bits.null || (*s1)[0] != '0'))
		*s1 = ft_strjoinre(c, *s1, 2);
	else if (fl->bits.null)
		(*s1)[0] = c[0];
	if (len != ft_strlen(*s1) && (*s1)[len] == ' ')
		(*s1)[len] = '\0';
}

void	ft_f(char **tmp, va_list list, t_flags *fl)
{
	char	*s1;
	int		len;
	int		i;
	int		up;
	double	num;

	num = va_arg(list, double);
	len = 6;
	i = 0;
	up = 0;
	//printf("s = %s, n = %f\n", s1, num);
	if (fl->bits.flag)
		len = fl->bits.len;
	if (len > 0 || fl->bits.hesh)
		s1 = ft_strjoinre(ft_itoa(num), ".", 1);
	else
		s1 = ft_strdup(ft_itoa(num));
	s1 = ft_strjoinre(s1, ft_s2(len, num, &up), 3);
	if (up)
		ft_overup(&s1, num < 0);
	if (num < 0 && s1[0] != '-')
		s1 = ft_strjoinre("-", s1, 2);
	if (fl->bits.num)
		s1 = ft_long(s1, fl, ' ');
	if (fl->bits.plus || fl->bits.space)
		ft_plus_f(&s1, fl);
	*tmp = ft_strjoinre(*tmp, s1, 3);
	fl->bits.f = 0;
}

void	ft_persent(char **tmp, t_flags *fl)
{
	char	*res;

	res = ft_strdup("%");
	if (fl->bits.num > 0 || fl->bits.len > 0)
		res = ft_null(res, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	*tmp = ft_strjoinre(*tmp, res, 3);
}
