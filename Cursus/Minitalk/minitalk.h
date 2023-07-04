

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
void	ft_error(char *str);
void	ft_send_str(int pid, char *str);
void	ft_sig_handler(int sig);
void	ft_send_char(int pid, char c);
int ft_atoi(const char *str);
void	ft_print_char(char c);
void	ft_print_str(char *str);
void	ft_print_int(int n);
int	ft_atoi(const char *str);

#endif
