/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:07:13 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 01:08:28 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_a)
	{
		temp1 = *stack_a;
		temp2 = ft_lstbeforelast(*stack_a);
		*stack_a = ft_lstlast(*stack_a);
		temp2->next = NULL;
		(*stack_a)->next = temp1;
	}
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_b)
	{
		temp1 = *stack_b;
		temp2 = ft_lstbeforelast(*stack_b);
		*stack_b = ft_lstlast(*stack_b);
		(*stack_b)->next = temp1;
		temp2->next = NULL;
	}
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
