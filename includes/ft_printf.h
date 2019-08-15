/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:43:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/15 19:24:42 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <libft.h>
# include <stdarg.h>

typedef struct		s_bits
{
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	hesh : 1;
	unsigned int	null : 1;
	unsigned int	h : 1;
//	unsigned int	hh : 1;
	unsigned int	l : 1;
//	unsigned int	ll : 1;
	unsigned int	L : 1;
	unsigned int	d : 1;
	unsigned int	i : 1;
	unsigned int	u : 1;
	unsigned int	o : 1;
	unsigned int	x : 1;
	unsigned int	upper_x : 1;
	unsigned int	f : 1;
	unsigned int	e : 1;
	unsigned int	upper_e : 1;
	unsigned int	g : 1;
	unsigned int	a : 1;
	unsigned int	upper_a : 1;
	unsigned int	p : 1;
	unsigned int	n : 1;
	unsigned int	s : 1;
	unsigned int	c : 1;
	unsigned int	persent : 1;
}					t_bits;

typedef union		u_flags
{
	int				value;
	struct s_bits	bits;
	int				res;
}					t_flags;

int		ft_printf(const char *format, ...);
int		ft_parser(const char *str, va_list list, t_flags *fl);
void	ft_interpretator(const char *str, char **tmp, va_list list, t_flags *fl);
int		ft_valid(const char c);

int		ft_1st_percent(const char *str);

void	ft_csp(char **tmp, va_list list, t_flags *fl);
void	ft_diou(char **tmp, va_list list, t_flags *fl);
void	ft_x(char **tmp, va_list list, t_flags *fl);
#endif
