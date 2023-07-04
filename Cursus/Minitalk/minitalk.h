/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:52:45 by lseiberr          #+#    #+#             */
/*   Updated: 2023/07/04 15:52:47 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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

#endif
