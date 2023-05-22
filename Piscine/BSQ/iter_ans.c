/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_ans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:14:07 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 22:50:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//place les obstacles de map dans la reponse et l'affiche
void	ft_print_fusion(t_def tdef, t_index_tab i_tab, char **rect)
{
	int	i;

	i = 0;
	while (i < i_tab.size)
	{
		rect[i_tab.tab[i]][i_tab.tab[i + 1]] = tdef.mc_c;
		i += 2;
	}
	ft_printrect(rect, tdef);
}

//retourne 1 si aucun obstacle n'est trouve dans la zone
int	check_zone(t_coord *o_s, t_index_tab i_tab)
{
	int	i;

	i = 0;
	while (i < i_tab.size)
	{
		if (((i_tab.tab[i] >= o_s->x) && (i_tab.tab[i] < o_s->x + o_s->s)) \
		&& ((i_tab.tab[i + 1] >= o_s->y) \
		&& (i_tab.tab[i + 1] < o_s->y + o_s->s)))
		{
			return (1);
		}
		i += 2;
	}
	return (0);
}

int	ft_mint(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

//initialise certains parametres de ft_output
void	ft_init_output(t_def tdef, t_index_tab *i_tab, t_coord *o_s, char **map)
{
	*i_tab = ft_mc_index(tdef, map);
	o_s->x = 0;
	o_s->y = 0;
	o_s->s = ft_mint(tdef.raw_s, tdef.col_s);
}

//genere toutes les possibilites jusqu'a trouver la bonne puis affiche
void	ft_output(t_def tdef, char **map, t_index_tab i_tab, t_coord o_s)
{
	char	**rect;
	int		is_ok;

	rect = init_rect(tdef);
	is_ok = 1;
	while ((o_s.s > 0) && is_ok)
	{
		o_s.x = 0;
		while (((o_s.x + o_s.s) <= tdef.col_s) && is_ok)
		{
			o_s.y = 0;
			while (((o_s.y + o_s.s) <= tdef.raw_s) && is_ok)
			{
				is_ok = check_zone(&o_s, i_tab);
				if (!is_ok)
					ft_ans(tdef, i_tab, o_s, rect);
				o_s.y++;
			}
			o_s.x++;
		}
		o_s.s--;
	}
	if (is_ok)
		ft_printrect(map, tdef);
	ft_end_rect(tdef, rect);
}
