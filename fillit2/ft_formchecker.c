/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:03:42 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/25 18:27:26 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

unsigned int	*ft_formchecker(unsigned int *b)
{
	int				fd;
	int				ret;
	char			buf[1000];
	char			**tabi;
	
	fd = open("alltype_input", O_RDONLY);
	if (fd == -1)
		ft_putstr("formchecker has failed\n");
	ret = read(fd, buf, 1000);
	buf[ret] = '\0';
	close(fd);
	ret = ft_nodouble(buf, '\n', 'Z');
//	b = (unsigned int *)ft_memalloc(ret);
	fd = 0;
	tabi = ft_strsplit(buf, 'Z');

	while (tabi[fd] != 0)
	{
		b[fd] = ft_atobin(tabi[fd]);
		fd++;
	}
	b[fd] = 65535;
	return (b);
}
