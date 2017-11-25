/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:54:01 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/25 20:34:28 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_deleteit(char *result, int position, int j)
{
	while (result[position] != 0)
	{
		if (result[position] == 'A' + j)
			result[position] = '.';
		position++;
	}
}

static void	ft_fillit(char *result, unsigned int a, int position, int j)
{
	int				k;
	int				count;

	k = 0;
	count = 0;
	while (count < 4 && result[position] != 0)
	{
		if (result[position] == '.' && (a & (1 << k)))
		{
			count++;
			result[position] = 'A' + j;
		}
		if (result[position] != '\n')
			k++;
		position++;
	}
}


static int		ft_isfilled(char *result, unsigned int a, int position)
{
	int				count;
	int				j;

	count = 0;
	j = 0;
	while (count < 4 && result[position] != 0)
	{
		if (result[position] == '.' && (a & (1 << j)))
			count++;
		if (result[position] != '\n')
			j++;
		if (result[position] == '\n' && (a & (1 << j) && (a & (1 << (j - 1)))))
			return (0);
		position++;
		if (result[position] != '.' && result[position] != '\n' && (a & (1 << j)))
			return (0);
	}
	if (count < 4)
		return (0);
	else
		return (1);
}

int	  ft_backtracking(char *result, int position, unsigned int *a, int j)
{
	if (a[j] == 65535)
		return (1);
	if (result[position] != 0)
	{
		if (ft_isfilled(result, a[j], position))
		{
			ft_fillit(result, a[j], position, j);
			ft_putstr(result);
			ft_putchar('\n');
			if (ft_backtracking(result, 0, a, j + 1) == 1)
				return (1);
			ft_deleteit(result, 0, j);
		}
		return (ft_backtracking(result, position + 1, a, j));
	}
	return (0);
}