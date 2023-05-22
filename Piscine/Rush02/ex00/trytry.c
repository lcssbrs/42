/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trytry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:00:39 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/18 20:50:02 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_trouvenb(int fd)
{
	unsigned int	i;
	char	buf[1];
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * 126)))
		exit(1);
	read (fd, buf, 1);
	while (buf[0] == '\n')
		read (fd, buf, 1);
	while (buf[0] >= 48 && buf[i] <= 57)
	{
		str[i] = buf[0];
		read (fd, buf, 1);
		i++;
	}
	return (str);
}

char	*ft_trouvevaleur(int fd, char *buf)
{
	unsigned int	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * 126)))
		exit (1);
	while (buf[0] != '\n')
	{
		str[i] = buf[0];
		read (fd, buf, 1);
		i++;
	}
	return (str);
}

t_list	*ft_rush(char *fichier)
{
	unsigned int	i;
	int	fd;
	char	buf[1];
	t_list	*tab;
	char	*tmp;
	char	*tmp2;

	i = 0;
	fd = open(fichier, O_RDONLY);
	if (fd == -1 || !(tab = malloc(sizeof(t_list) * 33)))
		exit (1);
	while (i < 32)
	{
		tmp2 = ft_trouvenb(fd);
		tab[i].key = ft_atoi(tmp2);
		free(tmp2);
		read (fd, buf, 1);
		while (buf[0] == ' ')
		{
			read (fd, buf, 1);
		}
		if (buf[0] == ':')
		{
			read (fd, buf, 1);
		}
		while (buf[0] == ' ')
		{
			read (fd, buf, 1);
		}
		tmp = ft_trouvevaleur(fd, buf);
		tab[i].val = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	close (fd);
	return (tab);
}
