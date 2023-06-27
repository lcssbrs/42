//write a program called server from the minitalk project of 42 cursus
//this program will receive a string from the client and print it
//the string will be sent as a series of bits
//the server will print the string when it receives the end of transmission signal
//the server will print the string in the same order as it was sent
//write it with the 42 norm
//the server will be able to receive strings from multiple clients in the same time

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

void	ft_sig_handler(int sig)
{
    static int	i = 0;
    static char	c = 0;

    if (sig == SIGUSR1)
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
    ft_putchar('\n');
    signal(SIGUSR1, ft_sig_handler);
    signal(SIGUSR2, ft_sig_handler);
    while (1)
        pause();
    return (0);
}
