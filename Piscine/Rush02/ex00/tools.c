/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:26:28 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/18 20:13:24 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

char *ft_strdup(char *src)
{
	unsigned int	i;
	unsigned int	len;
	char	*dest;

	len = 0;
	i = 0;
	while(src[len] != '\0')
		len++;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	retour;
	unsigned int	menos;

	i = 0;
	menos = 1;
	retour = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == 45)
		menos *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		retour = retour * 10 + str[i] - 48;
		i++;
	}
	return (retour * menos);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
