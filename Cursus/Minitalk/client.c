
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
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
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
