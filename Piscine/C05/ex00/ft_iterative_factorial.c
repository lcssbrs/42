/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:58:58 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/11 17:22:32 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 0;
	j = 1;
	while (i++ < nb)
		j *= i;
	return (j);
}
