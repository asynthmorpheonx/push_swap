/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:26:04 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/08 19:05:19 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int i)
{
	t_list *current;
	t_list *temp;

	current = *stack_a;
	if ((*stack_a)->next)
	{
		temp = (*stack_a)->next->next;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = current;
		current->next = temp;
	}
	if (i)
		write(1, "\nsa\n", 4);
}

void	swap_b(t_list **stack_b, int i)
{
	t_list *current;
	t_list *temp;

	current = *stack_b;
	if ((*stack_b)->next)
	{
		temp = (*stack_b)->next->next;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = current;
		current->next = temp;
	}
	if (i)
		write(1, "\nsb\n", 4);
}

void	push_a(t_list **stack_a, t_list **stack_b, int i)
{
	t_list *temp1;
	t_list *temp2;

	if (*stack_b)
	{
		temp1 = (*stack_b)->next;
		temp2 = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp1;
		(*stack_a)->next = temp2;
		if (i)
			write(1, "\npa\n", 4);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b, int i)
{
	t_list *temp1;
	t_list *temp2;

	if (*stack_a)
	{
		temp1 = (*stack_a)->next;
		temp2 = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp1;
		(*stack_b)->next = temp2;
		if (i)
			write(1, "\npb\n", 4);
	}
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "\nss\n", 4);
}