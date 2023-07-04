/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:52:23 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/04 15:52:29 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
    int	i;
    int	n;
    int	sign;

    i = 0;
    n = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
        || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = n * 10 + str[i] - '0';
        i++;
    }
    return (n * sign);
}

void	ft_send_char(int pid, char c)
{
    int	i;

    i = 0;
    while (i < 8)
    {
        if (c & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        c = c >> 1;
        i++;
        usleep(100);
    }
}

void	ft_send_str(int pid, char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        ft_send_char(pid, str[i]);
        i++;
    }
    ft_send_char(pid, str[i]);
}

int	main(int argc, char **argv)
{
    int	pid;

    if (argc != 3)
        ft_error("Error: wrong number of arguments");
    pid = ft_atoi(argv[1]);
    if (pid < 0)
        ft_error("Error: invalid pid");
    ft_send_str(pid, argv[2]);
    return (0);
}
