/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:59:46 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/25 20:16:19 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makesquare(int size)
{
	char	*str;
	int		i;
	int		j;
	int		count;

	if (!(str = ft_strnew((size * size) + size)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		count = 0;
		while (count++ < size)
			str[i++] = '.';
		str[i++] = '\n';
		j++;
	}
	return (str);
}
