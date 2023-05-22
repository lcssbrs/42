/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:44:32 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 22:52:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

//initialise les informations sur la map
void	ft_init_def(t_def *tdef, char *str)
{
	tdef->col_s = ft_getnumbersfirstline(str);
	tdef->raw_s = get_lenline(str);
	tdef->empty_c = ft_getfirstchar(str);
	tdef->mc_c = ft_getsecondchar(str);
	tdef->full_c = ft_getthirdchar(str);
}

void	for_the_nooorm(int file, char c, char *fl)
{
	int	cnl;

	cnl = ft_getnumbersfirstline(fl);
	while (cnl > 0)
	{
		read(1, &c, 1);
		write(file, &c, 1);
		if (c == '\n')
			cnl--;
	}
	close(file);
}

//lit l'entree standard et retourne la chaine du map
int	ft_siread(void)
{
	char	c;
	char	*fl;
	int		read_output;

	read_output = open("read_output", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	read(1, &c, 1);
	write(read_output, &c, 1);
	while (c != '\n')
	{
		read(1, &c, 1);
		write(read_output, &c, 1);
	}
	fl = ft_getstr_read("read_output");
	if (check_fl(fl) && (ft_getnumbersfirstline(fl) != 0))
	{
		for_the_nooorm(read_output, c, fl);
		free(fl);
		return (1);
	}
	else
	{
		free(fl);
		return (0);
	}
}

//lance le programme a partir de la lecture de l'entree standard
void	ft_launch0(void)
{
	t_index_tab	i_tab;
	t_def		map_def;
	t_coord		o_s;
	char		**map;
	char		*map_str;

	if (ft_siread())
	{
		map_str = ft_getstr("read_output");
		if (check_tab(map_str, "read_output"))
		{
			ft_init_def(&map_def, map_str);
			map = ft_strtotab(map_str, map_def);
			ft_init_output(map_def, &i_tab, &o_s, map);
			ft_output(map_def, map, i_tab, o_s);
			ft_end_rect(map_def, map);
			free(i_tab.tab);
		}
		else
			write(2, "map error\n", 10);
		free(map_str);
	}
	else
		write(2, "map error\n", 10);
}

//lance le programme a partir de la lecture des fichiers en argument
void	ft_launch1(int ac, char *av[], int i)
{
	t_index_tab	i_tab;
	t_def		map_def;
	t_coord		o_s;
	char		**map;
	char		*map_str;

	while (i < ac)
	{
		map_str = ft_getstr(av[i]);
		if (check_fl(map_str) && check_tab(map_str, av[i]))
		{
			ft_init_def(&map_def, map_str);
			map = ft_strtotab(map_str, map_def);
			ft_init_output(map_def, &i_tab, &o_s, map);
			ft_output(map_def, map, i_tab, o_s);
			ft_end_rect(map_def, map);
			free(i_tab.tab);
		}
		else
			write(2, "map error\n", 10);
		free(map_str);
		i++;
	}
}
