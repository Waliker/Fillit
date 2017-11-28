/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:54:01 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/28 14:51:26 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_deleteit(char *result, t_cursor cursor, int j)
{	
	cursor.posi = 0;
	while (result[cursor.posi] != 0)
	{
		if (result[cursor.posi] == 'A' + j)
			result[cursor.posi] = '.';
		cursor.posi++;
	}
}

static void	ft_fillit(char *result, unsigned int a, t_cursor cursor, int j)
{
	int				k;
	int				count;

	k = 0;
	count = 0;
	while (count < 4)
	{
		cursor.check = cursor.posi + (k % 4);
		while (a & (1 << k))
		{
			result[cursor.check++] = 'A' + j;
			count++;
			k++;
		}
		while (!(a & (1 << k)))
			k++;
		if (count > 0)
			cursor.posi = cursor.posi + cursor.size + 1;
	}
}

static int		ft_isfilled(char *result, unsigned int a, t_cursor cursor)
{
	int				count;
	int				j;

	count = 0;
	j = 0;
	while (count < 4 && cursor.posi <= (cursor.size * cursor.size) + cursor.size)
	{
		cursor.check = cursor.posi + (j % 4);
		while (a & (1 << j))
		{
			if (result[cursor.check++] == '.')
				count++;
			else
				return (0);
			j++;
		}
		while (!(a & (1 << j)))
			j++;
		if (count > 0)
			cursor.posi = cursor.posi + cursor.size + 1;
	}
	if (count < 4)
		return (0);
	else
		return (1);
}

int	  ft_backtracking(char *result, t_cursor cursor, unsigned int *a, int j)
{
	if (a[j] == 65535)
		return (1);
	if (result[cursor.posi] != 0)
	{
		while (!(ft_isfilled(result, a[j], cursor)) && result[cursor.posi] != 0)
			cursor.posi = cursor.posi + 1;
		if (result[cursor.posi] != 0)
		{
			ft_fillit(result, a[j], cursor, j);
			cursor.check = cursor.posi;
			cursor.posi = 0;
			if (j == 0)
			{
				ft_putstr(result);
				ft_putchar('\n');
			}
			if (ft_backtracking(result, cursor, a, j + 1) == 1)
				return (1);
			cursor.posi = cursor.check;
			ft_deleteit(result, cursor, j);
			cursor.posi = cursor.posi + 1;
			return (ft_backtracking(result, cursor, a, j));
		}
	}
	return (0);
}