/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:08:23 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/07 18:34:56 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int		ft_perror(void);
t_list	*sort_it_in_list(long *nbrs);
long	*c_to_d(char **c_arg, int *index);
long	*turn_it_into_int(char *arg, int *index);
void	ft_free(char **s1, char **s2);
char	*join_all(int ac, char **av);
int		check_first(int ac, char **av);
int		valid_number(char *str);
void	check_for_doubles(long *numbers, int end);
int		check_if_emty(char *arg);

#endif