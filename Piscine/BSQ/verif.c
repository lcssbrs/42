/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:00:34 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/21 22:53:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//verifie au'il y a autant de ligne que le nombre donnee
int	verif_ligne(char *str, int len, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			k++;
		i++;
	}
	k -= 1;
	if (k != j)
	{
		return (0);
	}
	return (1);
}

//verifie que les caracteres dans la chaine sont soit des obstacles ou des voids
int	verif_char(char *str, int len, char a, char b)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	while (i < len)
	{
		if (str[i] != a && str[i] != b && str[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

//verifie que les caracteres de la premieres lignes sont differents
int	verif_charfirstline(char a, char b, char c)
{
	if (a == b || a == c || c == b)
	{
		return (0);
	}
	return (1);
}

int	check_fl(char *str)
{
	int	a;
	int	b;
	int	c;

	if (!verif_firstline(str))
		return (0);
	a = ft_getfirstchar(str);
	b = ft_getsecondchar(str);
	c = ft_getthirdchar(str);
	if (!verif_threechar(a, b, c))
		return (0);
	if (!verif_charfirstline(a, b, c) || !verif_lenfirstline(str))
		return (0);
	return (1);
}

int	check_tab(char *str, char *file)
{
	int		len;
	int		slen;
	int		j;
	char	fc;
	char	sc;

	len = ft_findlen(file);
	j = ft_getnumbersfirstline(str);
	fc = ft_getfirstchar(str);
	sc = ft_getsecondchar(str);
	slen = get_lenline(str);
	if (!verif_ligne(str, len, j) \
	|| !verif_lenline(str, slen, ft_getnumbersfirstline(str)) \
	|| !verif_char(str, len, fc, sc))
		return (0);
	return (1);
}
