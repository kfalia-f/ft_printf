/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:41:51 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/22 20:10:41 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		main()
{
	//char	*str = "test";
	//char	c = 'A';

	ft_printf("d%10d\n", 123);
	ft_printf("x%10x\n", 123);
	ft_printf("o%10o\n", 123);
	ft_printf("u%10u\n", 123);
	//ft_printf("%d\n", str);
	//ft_printf("hi %X its %d mini %s       %c\n", 7467, -1000, str, c);
	//ft_printf("hi %X its %d mini %s       %c\n", 7467, -1000, str, c);
	//printf("hi %d %d %d\n", 123456789, 2, 3);
	return (0);
}
