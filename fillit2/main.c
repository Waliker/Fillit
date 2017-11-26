/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:43:07 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/25 20:26:58 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char	**ft_filetotab(char *file)
{
	int		fd;
	int		ret;
	char	buf[1000000];
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed");
	ret = read(fd, buf, 1000000);
	buf[ret] = '\0';
	ft_putstr(buf);
	close(fd);
	ft_nodouble(buf, '\n', 'Z');
	tab = ft_strsplit(buf, 'Z');
	return (tab);
}

int		main(int argc, char **argv)
{
	char		**tab;
	int			i;
	int			j;
//	int			count;
	unsigned int	*a;
	char		*result;
	unsigned int	*b;
	t_cursor		cursor;

	if (argc > 0)
	{
		tab = ft_filetotab(argv[1]);
		i = 0;
		a = (unsigned int *)ft_memalloc(300);
		b = (unsigned int *)ft_memalloc(100);
		while (tab[i] != 0)
		{
			a[i] = ft_atobin(tab[i]);
			i++;
		}
		printf("valeur de i :%d\n", i);
		a[i] = 65535;
		i = 0;
		while (a[i] != 65535)
		{
			i++;
			printf("Valeur de a[%d] : %d\n", i, a[i]);
		}
		i = 0;
/*		while (a[i] != 65535)
		{
			j = 0;
			count = 0;
			while (a[j] != 65535)
			{
				if (a[j] % a[i] == 0)
					count++;
				j++;
			}
			printf("Nombre de modulo de a[%d] : %d\n", i, count);
			i++;
		}*/
		i = 0;
		b = ft_formchecker(b);
		ft_putstr("Coucou ***** dernier a :");
		ft_putnbr(a[4]);
		ft_putchar('\n');
		while (b[i] != 65535)
		{
			ft_putnbr(b[i]);
			ft_putchar('\n');
			i++;
		}
		i = 0;
		while(a[i] != 65535)
		{
			j = 0;
			while (a[i] % b[j] != 0 && b[j] != 65535)
				j++;
			a[i] = b[j];
			i++;
		}
		printf("Dernier a[%d] : %d\n", i , a[i]);
		printf("Premier a[0] : %d\n", a[0]);
		j = ft_sqrt(i) * 2;
		result = ft_makesquare(j);
		cursor.size = ft_sqrt(i) * 2;
		cursor.posi = 0;
		cursor.check = 0;
		printf("Grille avnt :\n%s\n", result);
		ft_backtracking(result, cursor, a, 0);
		printf("Grille apres :\n%s\n", result);
	}
	return (0);
}
