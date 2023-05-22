/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:01:51 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/12 18:53:00 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	destlen;
	int	i;

	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		*strs = NULL;
		return (*strs);
	}
	*strs = (char *)(malloc(sizeof (int) * size));
	while (i != size)
	{
		while (*strs[i] == '\0')
		{
			ft_strcat(*strs, sep);
		}
		i++;
	}
	return (*strs);
}
