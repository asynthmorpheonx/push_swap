/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:06 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 01:28:18 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
void	ft_free(char **s1, void *s2);
long	*c_to_d(char **c_arg, int *index);
long	*turn_it_into_int(char *arg, int *index);
void	check_for_doubles(long *numbers, int end);
void	check_if_valid(char **c_arg);
char	*join_all(int ac, char **av);
int		sub_check(char *c_arg);
void	ft_perror(void);
t_list	*stor_in_list(long *nbrs, int end);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);
int		check_if_instruction(char	*str);
void	user_sort_execution(char *instruction, t_list **a, t_list **b);
void	read_nd_do(t_list **a, t_list **b);

#endif