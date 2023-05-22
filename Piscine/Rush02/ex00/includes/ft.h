/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:40:51 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/18 14:59:19 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_list
{
	unsigned int	key;
	char	*val;
}		t_list;
char	*ft_strdup(char *src);
int	ft_strlen(char	*str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strcpy( char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char *src);
unsigned int	ft_atoi(const char *str);
char	*ft_trouvenb(int fd);
char	*ft_trouvevaleur(int fd, char *buf);
t_list	*ft_rush(char *fichier);

#endif
