/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_remplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:50:24 by lseiberr          #+#    #+#             */
/*   Updated: 2023/06/21 11:33:04 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] !='\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_search(char *str, char c, char d)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			str[i] = d;
		i++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **ag)
{
	int	count;
	int	count2;

	count = ft_strlen(ag[2]);
	count2 = ft_strlen(ag[3]);
	if (ac == 4 && count == 1 && count2 == 1)
		ft_putstr(ft_search(ag[1], ag[2][0], ag[3][0]));
	ft_putchar('\n');
}
