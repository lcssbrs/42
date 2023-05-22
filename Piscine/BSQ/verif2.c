/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:30:12 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/21 18:08:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//verifie que la premiere ligne est d'au moins 4 caracteres
int	verif_firstline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (i < 4)
	{
		return (0);
	}
	else
		return (1);
}

//verifie la taille de la premiere ligne (bons nombres de caracteres)
int	verif_lenfirstline(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = get_numnum(str);
	while (str[i] != '\n')
		i++;
	if (k != i - 3)
	{
		return (0);
	}
	return (1);
}

int	ft_while(char *str, int i)
{
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\n')
		i++;
	i++;
	return (i);
}

// verifie la longueur de chaque ligne
int	verif_lenline(char *str, int k, int nb)
{
	int	i;
	int	o;
	int	s;

	s = 0;
	i = 0;
	i = ft_while(str, i);
	while (s < nb - 1)
	{
		o = 0;
		while (str[i + o] != '\n')
			o++;
		if (o != k)
		{
			return (0);
		}
		i += o + 1;
		s++;
	}
	return (1);
}

//verifie que les caracteres soient imprimables
int	verif_threechar(char a, char b, char c)
{
	if (!((a >= ' ' && a <= '~') && \
	(b >= ' ' && b <= '~') && (c >= ' ' && c <= '~')))
	{
		return (0);
	}
	return (1);
}
