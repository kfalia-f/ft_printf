/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:04:07 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/02 14:25:33 by kfalia-f         ###   ########.fr       */
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
	k = 0;
	if (len > fl->bits.len)
		while (i < len - fl->bits.len)
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

char	*ft_null(char *str, t_flags *fl, int num, char c)
{
	int		len;
	int		i;
	int		k;
	char	*tmp;

	if (fl->bits.null || num == fl->bits.len)
		c = '0';
	len = ft_strlen(str);
	if ((len > fl->bits.num && !fl->bits.len) || (!len && !fl->bits.num))
		return (str);
	if (fl->bits.minus)
		return (ft_minus(str, len, fl, num));
	tmp = ft_memalloc(num + 1);
	i = 0;
	k = 0;
	while (i < num - len)
		tmp[i++] = c;
	if (fl->bits.len > 0)
		while (i < num - fl->bits.len)
			tmp[i++] = c;
	while (i < num)
		tmp[i++] = str[k++];
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);
}
