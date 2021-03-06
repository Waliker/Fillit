/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:17:57 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/21 11:02:07 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != 0)
		{
			(*f)(&s[i]);
			i++;
		}
	}
}
