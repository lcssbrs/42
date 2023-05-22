/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:08:47 by tde-los-          #+#    #+#             */
/*   Updated: 2022/12/04 20:37:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	shape_0(char *shape)
{
	shape[0] = 'o';
	shape[1] = '-';
	shape[2] = 'o';
	shape[3] = 'o';
	shape[4] = '-';
	shape[5] = 'o';
	shape[6] = '|';
	shape[7] = ' ';
	shape[8] = '|';
}

void	shape_1(char *shape)
{
	shape[0] = '/';
	shape[1] = '*';
	shape[2] = '\\';
	shape[3] = '\\';
	shape[4] = '*';
	shape[5] = '/';
	shape[6] = '*';
	shape[7] = ' ';
	shape[8] = '*';
}

void	shape_2(char *shape)
{
	shape[0] = 'A';
	shape[1] = 'B';
	shape[2] = 'A';
	shape[3] = 'C';
	shape[4] = 'B';
	shape[5] = 'C';
	shape[6] = 'B';
	shape[7] = ' ';
	shape[8] = 'B';
}

void	shape_3(char *shape)
{
	shape[0] = 'A';
	shape[1] = 'B';
	shape[2] = 'C';
	shape[3] = 'A';
	shape[4] = 'B';
	shape[5] = 'C';
	shape[6] = 'B';
	shape[7] = ' ';
	shape[8] = 'B';
}

void	shape_4(char *shape)
{
	shape[0] = 'A';
	shape[1] = 'B';
	shape[2] = 'C';
	shape[3] = 'C';
	shape[4] = 'B';
	shape[5] = 'A';
	shape[6] = 'B';
	shape[7] = ' ';
	shape[8] = 'B';
}
