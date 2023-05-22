/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:49:08 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/21 19:46:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//Trouve la taille de l'input
int	ft_findlen(char argv[])
{
	char		a;
	int			len;
	int			fd;

	len = 0;
	fd = open(argv, O_RDONLY);
	while (read (fd, &a, 1))
		len++;
	close (fd);
	return (len);
}

//transorme input en string
char	*ft_getstr(char *argv)
{
	char		*str;
	int			fd;
	int			i;
	int			len;

	len = ft_findlen(argv);
	i = 0;
	fd = open(argv, O_RDONLY);
	str = malloc(sizeof(char) * len);
	while (read(fd, &str[i], 1))
	{
		i++;
	}
	close(fd);
	return (str);
}

//trouve le caractere void
char	ft_getfirstchar(char *str)
{
	char		first;
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	first = str[i - 3];
	return (first);
}

//trouve le caractere obstacle
char	ft_getsecondchar(char *str)
{
	char		second;
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	second = str[i - 2];
	return (second);
}

//trouve le caractere plein
char	ft_getthirdchar(char *str)
{
	char		third;
	int			i;

	i = 0;
	while (str[i] != '\n')
		i++;
	third = str[i - 1];
	return (third);
}
