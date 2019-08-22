/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:04:07 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/22 20:11:16 by kfalia-f         ###   ########.fr       */
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
		*tmp = ft_strjoinre(*tmp, "0", 1);
	if (fl->bits.x)
		*tmp = ft_strjoinre(*tmp, "0x", 1);
	else if (fl->bits.upper_x)
		*tmp = ft_strjoinre(*tmp, "0X", 1);
}

char	*ft_null(char *str, t_flags *fl)
{
	int		len;
	int		i;
	char	*tmp;
	char	c;

	c = ' ';
	if (fl->bits.null)
		c = '0';
	if (fl->bits.minus || !fl->bits.num)
		return (str);
	len = ft_strlen(str);
	if (len > fl->bits.num)
		return (str);
	tmp = ft_memalloc(fl->bits.num + 1);
	i = 0;
	while (i < fl->bits.num - len)
		tmp[i++] = c;
	len = 0;
	while (i < fl->bits.num)
		tmp[i++] = str[len++];
	tmp[i] = '\0';
	ft_strdel(&str);
	return (tmp);
}
