/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ans.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:41:06 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 22:50:45 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//retourne le rectangle initialise
char	**init_rect(t_def tdef)
{
	char	**rect;
	int		i;

	rect = malloc((tdef.col_s) * sizeof(char *));
	i = 0;
	while (i < (tdef.col_s))
	{
		rect[i] = malloc((tdef.raw_s) * sizeof(char));
		i++;
	}
	return (rect);
}

//free un rectangle
void	ft_end_rect(t_def tdef, char **rect)
{
	int	i;

	i = 0;
	while (i < tdef.col_s)
	{
		free(rect[i]);
		i++;
	}
	free(rect);
}

//affecte une possibilite en fonction de la taille de la possibilite 
//et de ses coordonnees d'origine(haut gauche)
//puis affiche la reponse
void	ft_ans(t_def tdef, t_index_tab i_tab, t_coord o_s, char **rect)
{
	int	i;
	int	j;

	i = 0;
	while (i < tdef.col_s)
	{
		j = 0;
		while (j < tdef.raw_s)
		{
			if (((i >= o_s.x) && (i < (o_s.x + o_s.s))) \
			&& ((j >= o_s.y) && (j < (o_s.y + o_s.s))))
				rect[i][j] = tdef.full_c;
			else
				rect[i][j] = tdef.empty_c;
			j++;
		}
		i++;
	}
	ft_print_fusion(tdef, i_tab, rect);
}

//quantite d'obstacles
int	ft_mc_qt(t_def tdef, char **map)
{
	int	i;
	int	j;
	int	qt;

	qt = 0;
	i = 0;
	while (i < tdef.col_s)
	{
		j = 0;
		while (j < tdef.raw_s)
		{
			if (map[i][j] == tdef.mc_c)
				qt++;
			j++;
		}
		i++;
	}
	return (qt);
}

//retourne un tableau d'indices ou se situent les obstacles
t_index_tab	ft_mc_index(t_def tdef, char **map)
{
	int			i;
	int			j;
	int			k;
	t_index_tab	i_tab;

	i_tab.size = 2 * ft_mc_qt(tdef, map);
	i_tab.tab = malloc(i_tab.size * sizeof(int));
	i = 0;
	k = 0;
	while (i < tdef.col_s)
	{
		j = 0;
		while (j < tdef.raw_s)
		{
			if (map[i][j] == tdef.mc_c)
			{
				i_tab.tab[k] = i;
				i_tab.tab[k + 1] = j;
				k += 2;
			}
			j++;
		}
		i++;
	}
	return (i_tab);
}
