/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utility.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:38:14 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 23:09:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_UTILITY_H
# define BSQ_UTILITY_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_def		t_def;
struct s_def
{
	int		col_s;
	int		raw_s;
	char	empty_c;
	char	mc_c;
	char	full_c;
};
typedef struct s_coord		t_coord;
struct s_coord
{
	int	x;
	int	y;
	int	s;
};
typedef struct s_index_tab	t_index_tab;
struct s_index_tab
{
	int	*tab;
	int	size;
};

t_index_tab	ft_mc_index(t_def tdef, char **map);
char		**init_rect(t_def tdef);
void		ft_ans(t_def tdef, t_index_tab i_tab, t_coord o_s, char **rect);
void		ft_printrect(char **sqr, t_def tdef);
void		ft_output(t_def tdef, char **map, t_index_tab i_tab, t_coord o_s);
void		ft_end_rect(t_def tdef, char **rect);
void		ft_launch1(int ac, char *av[], int i);
void		ft_init_def(t_def *tdef, char *str);
void		ft_print_fusion(t_def tdef, t_index_tab i_tab, char **rect);
void		ft_init_output(t_def tdef, t_index_tab *i_tab, \
		t_coord *o_s, char **map);
void		ft_launch0(void);
char		**ft_strtotab(char *str1, t_def tdef);
char		*ft_getstr(char argv[]);
char		ft_getfirstchar(char *str);
char		ft_getsecondchar(char *str);
char		ft_getthirdchar(char *str);
char		*ft_getstr_read(char *argv);
int			verif_lenline(char *str, int k, int nb);
int			ft_siread(void);
int			check_tab(char *str, char *file);
int			ft_getnumbersfirstline(char *str);
int			ft_findlen(char *argv);
int			ft_max_oss(t_def tdef, char **map);
int			ft_mint(int a, int b);
int			get_lenline(char *str);
int			check_fl(char *str);
int			get_numnum(char	*str);
int			verif_firstline(char *str);
int			verif_threechar(char a, char b, char c);
int			verif_lenfirstline(char *str);

#endif
