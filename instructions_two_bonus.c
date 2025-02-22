/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:06:05 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 01:08:54 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	swap_a(t_list **stack_a)
{
	t_list	*current;
	t_list	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		current = *stack_a;
		temp = (*stack_a)->next->next;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = current;
		current->next = temp;
	}
}

void	swap_b(t_list **stack_b)
{
	t_list	*current;
	t_list	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		current = *stack_b;
		temp = (*stack_b)->next->next;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = current;
		current->next = temp;
	}
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
