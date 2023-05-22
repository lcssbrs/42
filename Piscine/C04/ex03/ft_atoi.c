/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:09 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/08 13:44:51 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	ft_atoi(char *str)
{
	int	i;
	int	count_menos;
	int	retour;

	i = 0;
	count_menos = 0;
	retour = 0;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] != '\0' && (str[i] == 45 || str[i] == 43))
	{
		if (str[i] == 45)
			count_menos ++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		retour = (retour * 10) + (str[i] - 48);
		i++;
	}
	if (count_menos % 2 != 0)
		count_menos = -1;
	else
		count_menos = 1;
	return (retour * count_menos);
}
