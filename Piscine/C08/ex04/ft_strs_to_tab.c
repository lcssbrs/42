/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:39:54 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/13 09:52:15 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
#include <unistd.h>

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dest = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*structs;

	i = 0;
	structs = malloc(sizeof(struct s_stock_str) *(ac + 1));
	while (i < ac)
	{
		structs[i].size = ft_strlen(av[i]);
		structs[i].str = av[i];
		structs[i].copy = ft_strdup(av[i]);
		i++;
	}
	structs[i].str = 0;
	return (structs);
}
