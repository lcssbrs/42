/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:09:01 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/18 15:35:34 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft.h"

unsigned int	ft_dizaine(unsigned int n)
{
	if (n >= 90)
		return (90);
	else if (n >= 80)
		return (80);
	else if (n >= 70)
		return (70);
	else if (n >= 60)
		return (60);
	else if (n >= 50)
		return (50);
	else if (n >= 40)
		return (40);
	else if (n >= 30)
		return (30);
	else if (n >= 20)
		return (20);
	else if (n <= 20)
		return (n);
	else
		return (0);
}

unsigned int	ft_relou(unsigned int n)
{
	if (n >= 1000000000)
		return (1000000000);
	else if (n >= 1000000)
		return (1000000);
	else if (n >= 1000)
		return (1000);
	else if (n >= 100)
		return (100);
	else
		return (ft_dizaine(n));
}

void	ft_print(unsigned int n, t_list *tab, unsigned int *str)
{
	unsigned int	i;
	unsigned int	pleinsdezero;

	i = 0;
	pleinsdezero = ft_relou(n);
	if (pleinsdezero >= 100)
		ft_print(n / pleinsdezero, tab, str);
	if (*str == 0)
		write (1, " ", 1);
	*str = 0;
	while (tab[i].key != pleinsdezero)
		i++;
	ft_putstr(tab[i].val);
	if (pleinsdezero != 0 && n % pleinsdezero != 0)
		ft_print (n % pleinsdezero, tab, str);
}

int	main(int ac, char **ag)
{
	t_list *tab;
	unsigned int	*str;
	unsigned int	src;

	src = 1;
	str = &src;
	if (ac == 2)
	{
		if (ft_atoi(ag[1]) < 0)
		{
			write (1, "Error", 6);
			return (0);
		}
		tab = ft_rush("numbers.dict.txt");
		ft_print(ft_atoi(ag[1]), tab, str);
	}
	else
		write (1, "Dict Error", 11);
	return (0);
}
