/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:22:37 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/08/17 18:21:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoinre(char *s1, char *s2, int flag)
{
	char	*s;

	if ((s = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	if (flag == 1)
		free(s1);
	else if (flag == 2)
		free(s2);
	else
	{
		free(s1);
		free(s2);
	}
	return (s);
}
