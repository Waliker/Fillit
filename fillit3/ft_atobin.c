/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:40:18 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/28 18:16:09 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_atobin(char *str)
{
	int				j;
	int				n;
	unsigned int	a;

	j = 0;
	a = 0;
	n = 0;
	while (str[j] != 0)
	{
		if (str[j] == '\n')
			n++;
		if (str[j] == '#')
			a = a | (1 << (j - n));
		j++;
	}
	return (a);
}
