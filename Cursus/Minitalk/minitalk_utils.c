/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:03 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/04 15:55:09 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
    char	c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 0 && n <= 9)
    {
        c = n + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void	ft_putendl(char *str)
{
    ft_putstr(str);
    ft_putchar('\n');
}

void	ft_error(char *str)
{
    ft_putendl(str);
    exit(1);
}
