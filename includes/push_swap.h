/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:08:23 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 20:33:00 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

void	push_a(t_list **stack_a, t_list **stack_b, int i);
void	push_b(t_list **stack_a, t_list **stack_b, int i);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a, int i);
void	reverse_rotate_b(t_list **stack_b, int i);
void	check_for_doubles(long *numbers, int end);
long	*turn_it_into_int(char *arg, int *index);
long	*c_to_d(char **c_arg, int *index);
void	swap_a(t_list **stack_a, int i);
void	swap_b(t_list **stack_b, int i);
int		check_first(int ac, char **av);
void	ft_free(char **s1, void *s2);
char	*join_all(int ac, char **av);
void	check_if_emty(char *arg);
void	ft_perror(void);
int		sub_check(char *c_arg);
int		valid_number(char *str);
void	check_if_valid(char **c_arg);	
void	rotate_b(t_list **stack_b, int i);
void	rotate_a(t_list **stack_a, int i);
void	sort_b_to_a(t_list **a, t_list **b);
void	print_stack(t_list *stack, char c);
void	sort_in_array(long *nbrs, int index);
void	sort_pair(t_list **a, t_list **b, int i);
int		check_if_sorted_already(long *array, int end);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void	sort_in_b(long *array, t_list **a, t_list **b, int nbr_count);

#endif