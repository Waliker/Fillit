/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:59:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/25 16:30:37 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nodouble(char *s, char c, char d)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (s[i] != 0)
	{
		i++;
		if (s[i] == c && s[i - 1] == c)
		{
			s[i] = d;
			nbr++;
		}
	}
	return (nbr);
}
