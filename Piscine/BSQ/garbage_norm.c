/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:47:13 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 22:48:31 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//affiche un rectangle
void	ft_printrect(char **sqr, t_def tdef)
{
	int	i;
	int	j;

	i = 0;
	while (i < tdef.col_s)
	{
		j = 0;
		while (j < tdef.raw_s)
		{
			write(1, &sqr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

//change un nombre en son nombre de caractere
int	get_numnum(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i -= 4;
	while (str[j] >= '0' && str[j] <= '9' && j <= i)
		j++;
	return (j);
}
