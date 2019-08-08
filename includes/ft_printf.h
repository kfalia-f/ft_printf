/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:43:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/08 20:07:47 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <libft.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_parser(const char *str, va_list list);
int		ft_interpretator(const char *str, int *i, va_list list);
int		ft_valid(const char c);

#endif
