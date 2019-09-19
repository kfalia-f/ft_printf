/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:43:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/19 16:40:30 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct			s_bits
{
	unsigned int		ll : 1;
	unsigned int		hh : 1;
	unsigned int		minus : 1;
	unsigned int		plus : 1;
	unsigned int		space : 1;
	unsigned int		hesh : 1;
	unsigned int		null : 1;
	unsigned int		h : 1;
	unsigned int		l : 1;
	unsigned int		upper_l : 1;
	unsigned int		d : 1;
	unsigned int		i : 1;
	unsigned int		u : 1;
	unsigned int		o : 1;
	unsigned int		x : 1;
	unsigned int		upper_x : 1;
	unsigned int		f : 1;
	unsigned int		p : 1;
	unsigned int		s : 1;
	unsigned int		c : 1;
	unsigned int		persent : 1;
	int					res;
	int					num;
	int					len;
	int					flag;
	int					c_flag;
}						t_bits;

typedef union			u_flags
{
	int					value;
	struct s_bits		bits;
}						t_flags;

int						ft_printf(const char *format, ...);
int						ft_parser(const char *str, va_list list, t_flags *fl);
void					ft_interpretator(char **tmp, va_list list, t_flags *fl);
int						ft_valid(const char c);

int						ft_1st_percent(const char *str);
char					*ft_pull_res(char *str, int i);
char					*ft_16(unsigned long n, t_flags *fl);
int						ft_mom(int n1, int n2, int flag);
unsigned long long int	ft_convers(va_list list, t_flags *fl);
char					*ft_itoa_long(long long int n);
void					ft_write(char *str, t_flags *fl);
char					*ft_reverse_str(char *str);
int						first_dig(long long num);
void					ft_overup(char **str, int sign);

void					ft_plus_space(char **tmp, t_flags *fl);
void					ft_hesh(char **tmp, t_flags *fl);
char					*ft_null(char *str, t_flags *fl, int num, char c);
char					*ft_num_form(char *str, t_flags *fl, int num, char c);
char					*ft_len(char *str, t_flags *fl);
void					ft_persent(char **tmp, t_flags *fl);

void					ft_csp(char **tmp, va_list list, t_flags *fl);
void					ft_diou(char **tmp, va_list list, t_flags *fl);
void					ft_x(char **tmp, va_list list, t_flags *fl);
void					ft_f(char **tmp, va_list list, t_flags *fl);

#endif
