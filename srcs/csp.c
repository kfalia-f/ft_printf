/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:07:16 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/02 17:31:44 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	ft_spaces_c(char **tmp, int num, char *s)
{
	int		i;

	i = 0;
	while (i < num)
		s[i++] = ' ';
	s[i] = '\0';
	*tmp = ft_strjoinre(*tmp, s, 3);
}

void	ft_c(char **tmp, va_list list, t_flags *fl)
{
	char	*dst;
	char	*s;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	dst = ft_memalloc(2);
	dst[0] = va_arg(list, int);
	dst[1] = '\0';
	s = ft_memalloc(fl->bits.num);
	if (!fl->bits.minus)
		ft_spaces_c(tmp, fl->bits.num - 1, s);
	if (dst[0] == 0)
	{
		while ((*tmp)[i])
			i++;
		fl->bits.c_flag = i;
	}
	*tmp = ft_strjoinre(*tmp, dst, 3);
	if (fl->bits.minus)
		ft_spaces_c(tmp, fl->bits.num - 1, s);
	fl->bits.c = 0;
}

void	ft_s(char **tmp, va_list list, t_flags *fl)
{
	char	*dst;

	dst = ft_memalloc(10000);
	dst = ft_strcpy(dst, va_arg(list, char *));
	if (dst)
		dst = ft_strjoinre(dst, "", 1);
	else
	{
		free(dst);
		dst = ft_strdup("(null)");
	}
	if (fl->bits.len > 0 || fl->bits.num > 0)
		dst = ft_null(dst, fl, ft_mom(fl->bits.len, fl->bits.num, 1), ' ');
	*tmp = ft_strjoinre(*tmp, dst, 3);
	fl->bits.s = 0;
}

void	ft_p(char **tmp, va_list list, t_flags *fl)
{
	unsigned long		b;
	char				*str;

	b = (unsigned long)va_arg(list, void *);
	str = ft_strjoinre("0x", ft_16(b, fl), 2);
	*tmp = ft_strjoinre(*tmp, str, 3);
	fl->bits.p = 0;
}

void	ft_csp(char **tmp, va_list list, t_flags *fl)
{
	if (fl->bits.c)
		ft_c(tmp, list, fl);
	else if (fl->bits.s)
		ft_s(tmp, list, fl);
	else
		ft_p(tmp, list, fl);
}
