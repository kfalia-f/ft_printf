/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:19:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/23 18:11:38 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_llhh(const char *str, int k, t_flags *fl)
{
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
		fl->bits.len = ft_atoi(str + k);
	}
	while (ft_isdigit(str[k]))
		k++;
	*i = k;
}

void	ft_flags(const char *str, int *i, t_flags *fl)
{
	char	*cmp;
	char	*s;
	size_t	bits_to_shift;
	int		k;

	cmp = "JH-+ #0hlLdiuoxXfpsc%";
	k = *i - 1;
	while (ft_strchr("diuoxXfcsp%", str[++k]) == NULL)
	{
		if (str[k] == '.' || ft_isdigit(str[k]))
			ft_pars_dig(str, &k, fl);
		if (str[k] == 'l' || str[k] == 'h')
			if (ft_llhh(str, k, fl))
			{
				k++;
				continue ;
			}
		if ((s = ft_strchr(cmp, str[k])) != NULL)
			bits_to_shift = s - cmp;
		fl->value |= (1 << bits_to_shift);
	}
	s = ft_strchr(cmp, str[k]);
	bits_to_shift = s - cmp;
	fl->value |= (1 << bits_to_shift);
	*i = k;
}

char	*ft_pull_tmp(const char *str)
{
	int		i;
	char	*dst;

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

	i = 0;
	tmp = ft_memalloc(1000);
	tmp = ft_strncat(tmp, str, ft_1st_percent(str));
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_flags(str, &i, fl);
			ft_interpretator(str + i + 1, &tmp, list, fl);
			fl->bits.res += 1;
			tmp = ft_strjoinre(tmp, ft_pull_tmp(str + i), 3);
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	if (str[i - 1] == '\n')
		tmp = ft_strjoinre(tmp, "\n", 1);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (fl->bits.res);
}
