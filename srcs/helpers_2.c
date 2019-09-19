/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:35:17 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/09/19 17:56:41 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char    *ft_itoa_long(long long int n)
{
	char    s[50];
	char    *res;
	int     neg;
	int     i;
	int     j;

	i = 0;
	j = 0;
	neg = n < 0 ? -1 : 1;
	while (neg * n > 9 || neg * n < 0)
	{
		s[i++] = '0' + neg * (n % 10);
		n = n / 10;
	}
	s[i++] = '0' + neg * n;
	if (neg < 0)
		s[i++] = '-';
	if ((res = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = s[j++];
	return (res);
}

int		ft_mom(int n1, int n2, int flag)
{
	if (flag == 1)
	{
		if (n1 > n2)
			return (n1);
		return (n2);
	}
	else
		if (n1 > n2)
			return (n2);
	return (n1);
}

int		first_dig(long long num)
{
	num *= num < 0 ? - 1 : 1;
	while (num >= 10)
		num /= 10;
	return (num);
}

char	*ft_reverse_str(char *str)
{
	char 	*tmp;
	int		i;
	int 	k;

	i = ft_strlen(str);
	k = 0;
	tmp = ft_memalloc(--i + 2);
	//printf("s  -  %s, i   -  %d\n", str, i);
	while (i >= 0)
		tmp[k++] = str[i--];
	tmp[k] = '\0';
	ft_strdel(&str);
	return (tmp);
}

void	ft_overup(char **str, int sign)
{
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '.')
		i++;
	i--;
	while (i >= 0)
	{
		if ((*str)[i] == '9')
			(*str)[i--] = '0';
		else
		{
			(*str)[i] += 1;
			break ;
		}
	}
	if ((*str)[0] == '.')
	{
		(*str)[0] = '1';
		//*str = ft_strjoinre("-", *str, 2);
	}
	else if ((*str)[0] == '0')
		*str = ft_strjoinre("1", *str, 2);
	if (sign == 1 && (*str)[0] != '-')
		*str = ft_strjoinre("-", *str, 2);
}
