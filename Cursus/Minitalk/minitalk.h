//write a header called minitalk.h from the minitalk project of 42 cursus
//this header will contain all the prototypes of the functions used in the project
//write it with the 42 norm
//the header will be included in both the client and the server
//the header will be protected from double inclusion
//the header will be in the same directory as the client and the server
//use the client and server snippets to test your header
//submit the header file only

// Path: Cursus/Minitalk/minitalk.h

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
