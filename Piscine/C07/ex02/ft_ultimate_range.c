/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:51:55 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/12 15:58:54 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = 0;
	j = min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (malloc(sizeof(int) * (max - min)));
	if (!(*range))
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = j;
		i++;
		j++;
	}
	return (max - min);
}
