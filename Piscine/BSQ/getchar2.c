/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getchar2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:00 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/21 22:48:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//trouve le numero de ligne afficher sur la premiere ligne
int	ft_getnumbersfirstline(char *str)
{
	int	i;
	int	retour;
	int	j;

	i = 0;
	retour = 0;
	while (str[i] != '\n')
		i++;
	j = i - 4;
	i = 0;
	while (i <= j && str[i] >= '0' && str[i] <= '9')
	{
		retour = retour * 10 + str[i] - '0';
		i++;
	}
	return (retour);
}

//trouve la longueur de la deuxieme ligne
int	get_lenline(char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	k = 0;
	while (str[i + k] != '\n')
		k++;
	return (k);
}

//change le string en tableau
char	**ft_strtotab(char *str1, t_def tdef)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	tab = init_rect(tdef);
	while (str1[k] != '\n')
		k++;
	k++;
	i = 0;
	while (i < tdef.col_s)
	{
		j = 0;
		while (str1[k] != '\n')
		{
			tab[i][j] = str1[k];
			j++;
			k++;
		}
		i++;
		k++;
	}
	return (tab);
}

int	get_lenfirstline(char *argv)
{
	int		k;
	int		file;
	char	c;

	k = 1;
	c = ' ';
	file = open(argv, O_RDONLY);
	read(file, &c, 1);
	while (c != '\n')
	{
		read(file, &c, 1);
		k++;
	}
	close(file);
	return (k);
}

char	*ft_getstr_read(char *argv)
{
	char		*str;
	int			fd;
	int			i;
	int			len;

	len = get_lenfirstline(argv);
	i = 0;
	fd = open(argv, O_RDONLY);
	str = malloc(sizeof(char) * len);
	while (i < len)
	{
		read(fd, &str[i], 1);
		i++;
	}
	close(fd);
	return (str);
}
