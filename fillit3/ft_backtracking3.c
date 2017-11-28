/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:54:01 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/28 19:58:49 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Permet de compter le nombre de cases vides inutilisables en ligne type :
// AAABBB
// .A...C -> la tu as a 4 cases inutilisables
// DDDDCC
static int	ft_emptyline(char *result, t_cursor cursor)
{
	int		i;
	int		emptysize;
	int		isempty;
	int		j;

	i = cursor.size + 1;
	j = cursor.size + 1;
	isempty = 0;
	while (i < cursor.check && i / j < cursor.size - 1)
	{
		emptysize = 0;
		// emptysize < 4 car si c'est egale, une barre horizontale peut passer
		while (result[i++] == '.' && emptysize < 4 && result[i - j] != '.' && result[i + j] != '.')
			++emptysize;
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}

// Pareil que la foncton au dessus mais avec les colonnes
static int	ft_emptycol(char *result, t_cursor cursor)
{
	int		i;
	int		emptysize;
	int		isempty;
	int		k;

	i = 1;
	isempty = 0;
	while (i < cursor.check && i <= cursor.size)
	{
		k = i;
		emptysize = 0;
		while (result[k] == '.' && emptysize < 4 && result[k - 1] != '.' && result[k + 1] != '.')
		{
			++emptysize;
			k = k + cursor.size + 1;
		}
		if (emptysize < 4)
			isempty = isempty + emptysize;
		++i;
	}
	return (isempty);
}


static void	ft_deleteit(char *result, t_cursor cursor, int j)
{	
	cursor.posi = 0;
	while (result[cursor.posi] != 0)
	{
		if (result[cursor.posi] == 'A' + j)
			result[cursor.posi] = '.';
		++cursor.posi;
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
			++count;
			++k;
		}
		while (!(a & (1 << k)))
			++k;
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
				++count;
			else
				return (0);
			++j;
		}
		while (!(a & (1 << j)) && count < 4)
			++j;
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
// voir deux fonctions en haut du fichier. Si le nombre de cases inutilisables est superieur au nombre de cases vides possibles pour cette taille de carre, faut replacer les pieces
	if (ft_emptyline(result, cursor) + ft_emptycol(result, cursor) > (cursor.size * cursor.size) - (cursor.form * 4))
		return (0);
	while (!(ft_isfilled(result, a[j], cursor)) && result[cursor.posi] != 0)
		++cursor.posi;
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
		++cursor.posi;
		return (ft_backtracking(result, cursor, a, j));
	}
	return (0);
}
