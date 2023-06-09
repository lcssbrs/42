/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:39:05 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/08 11:33:00 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb >= 2)
	{
		while (i <= nb / 2)
		{
			if (!(nb % i))
				return (0);
			else
				i++;
		}
		return (1);
	}
	return (0);
}
