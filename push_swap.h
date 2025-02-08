/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:08:23 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/08 19:33:27 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void	swap_both(t_list **stack_a, t_list **stack_b);
void	check_for_doubles(long *numbers, int end);
long	*turn_it_into_int(char *arg, int *index);
long	*c_to_d(char **c_arg, int *index);
void	swap_a(t_list **stack_a, int i);
void	swap_b(t_list **stack_b, int i);
int		check_first(int ac, char **av);
void	ft_free(char **s1, char **s2);
t_list	*sort_it_in_list(long *nbrs);
char	*join_all(int ac, char **av);
void	check_if_valid(char **c_arg);	
int		check_if_emty(char *arg);
int		valid_number(char *str);
int		sub_check(char *c_arg);
int		ft_perror(void);
void	push_a(t_list **stack_a, t_list **stack_b, int i);
void	push_b(t_list **stack_a, t_list **stack_b, int i);
void	rotate_b(t_list **stack_b, int i);
void	rotate_a(t_list **stack_a, int i);

#endif