/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:19:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/20 20:40:39 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_llhh(const char *str, int k, t_flags *fl)
{
	if (str[k] == 'L')
	{
		fl->bits.upper_l = 1;
		return (0);
	}
	if (str[k + 1] == 'h')
	{
		fl->value |= (1 << 1);
		return (1);
	}
	else if (str[k + 1] == 'l')
	{
		fl->value |= (1 << 0);
		return (1);
	}
	else if (str[k] == 'l')
		fl->value |= (1 << 8);
	else if (str[k] == 'h')
		fl->value |= (1 << 7);
	return (0);
}

void	ft_pars_dig(const char *str, int *i, t_flags *fl)
{
	int		k;

	k = *i;
	if (str[k] == '0')
	{
		fl->bits.null = 1;
		k++;
	}
	if (ft_isdigit(str[k]))
		fl->bits.num = ft_atoi(str + k);
	while (ft_isdigit(str[k]))
		k++;
	if (str[k] == '.')
	{
		k++;
		fl->bits.flag = 1;
		fl->bits.len = ft_atoi(str + k);
	}
	while (ft_isdigit(str[k]))
		k++;
	*i = k - 1;
}

void	ft_flags(const char *str, int *i, t_flags *fl)
{
	char	*cmp;
	char	*s;
	size_t	bits_to_shift;
	int		k;

	cmp = "JH-+ #0hlLdiuoxXfpsc%";
	k = *i;
	while (str[k] && ft_strchr("diuoxXfcsp%", str[++k]) == NULL)
	{
		if (str[k] == '.' || ft_isdigit(str[k]))
			ft_pars_dig(str, &k, fl);
		if (str[k] == 'l' || str[k] == 'h' || str[k] == 'L')
			if (ft_llhh(str, k, fl))
			{
				k++;
				continue ;
			}
		if ((s = ft_strchr("JH-+ #", str[k])) != NULL)
		{
			bits_to_shift = s - "JH-+ #";
			fl->value |= (1 << bits_to_shift);
		}
	}
	s = ft_strchr(cmp, str[k]);
	bits_to_shift = s - cmp;
	fl->value |= (1 << bits_to_shift);
	*i = k + 1;
}

char	*ft_pull_tmp(const char *str)
{
	int		i;
	char	*dst;

	if (str[0] == '%')
		return (ft_strdup(""));
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	dst = ft_memalloc(i + 1);
	ft_strncpy(dst, str, i);
	dst[i] = '\0';
	return (dst);
}

int		ft_parser(const char *str, va_list list, t_flags *fl)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_memalloc(1);
	tmp = ft_strncat(tmp, str, ft_1st_percent(str));
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_flags(str, &i, fl);
			//printf ("i = %d\n", i);
			if (fl->bits.minus)
				fl->bits.null = 0;
			if (str[i] != '\0' || str[i - 1] != '\0')
			{
				ft_interpretator(&tmp, list, fl);
				tmp = ft_strjoinre(tmp, ft_pull_tmp(str + i), 3);
			}
			if (str[i] == '\0')
				break ;
			if (str[i] == '%')
				i--;
		}
	}
	fl->bits.res = ft_strlen(tmp);
	ft_write(tmp, fl);
//	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (fl->bits.res);
}
