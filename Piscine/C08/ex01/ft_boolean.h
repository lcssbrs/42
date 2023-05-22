/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:00:44 by lseiberr          #+#    #+#             */
/*   Updated: 2022/12/12 20:04:11 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG " I have an odd number of arguments.\n"
# define SUCCESS 0
# define EVEN(x) x % 2 ==0

typedef int	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
