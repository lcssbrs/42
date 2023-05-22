/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:29:23 by gdornic           #+#    #+#             */
/*   Updated: 2022/12/21 22:43:53 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_utility.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_launch0();
	}
	else
	{
		ft_launch1(argc, argv, i);
	}
	return (0);
}