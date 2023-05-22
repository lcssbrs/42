/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:29:22 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/03 14:10:33 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ecrit(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_ecrit (a / 10 + '0');
			ft_ecrit (a % 10 + '0');
			write (1, " ", 1);
			ft_ecrit (b / 10 + '0');
			ft_ecrit (b % 10 + '0');
			if (a != 98)
			{
				write (1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
