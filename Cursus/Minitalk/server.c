/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:52:38 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/04 15:52:39 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"


void	ft_sig_handler(int sig)
{
    static int	i = 0;
    static char	c = 0;

    if (sig == SIGUSR2)
        c = c | (1 << i);
    i++;
    if (i == 8)
    {
        if (c == '\0')
            ft_putendl("");
        else
            ft_putchar(c);
        i = 0;
        c = 0;
    }
}

int	main(void)
{
    pid_t	pid;

    pid = getpid();
    ft_putnbr(pid);
    signal(SIGUSR1, ft_sig_handler);
    signal(SIGUSR2, ft_sig_handler);
    ft_putchar('\n');
    while (1)
        pause();
    return (0);
}

