/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:19:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 20:54:04 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_flags(const char *str, int *i, t_flags *fl)
{
	char	*cmp;
	char	*s;
	size_t	bits_to_shift;
	int		k;

	cmp = "JH-+ #0hlLdiuoxXfpsc%";
	k = *i;
	while (ft_strchr("diuoxXfcsp%", str[++k]) == NULL)
	{
		if (str[k] == 'l' && str[k + 1] == 'l')
		{
			fl->value |= (1 << 1);
			continue ;
		}
		if (str[k] == 'h' && str[k + 1] == 'h')
		{
			fl->value |= (1 << 2);
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
	fl->res = 0;
	tmp = ft_memalloc(1000);
	tmp = ft_strncat(tmp, str, ft_1st_percent(str));
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_flags(str, &i, fl);
			ft_interpretator(str + i + 1, &tmp, list, fl);
			fl->res += 1;
			tmp = ft_strjoinre(tmp, ft_pull_tmp(str + i + 1), 3);
		}
		i++;
	}
	ft_putstr(tmp);
	ft_strdel(&tmp);
	return (fl->res);
}
