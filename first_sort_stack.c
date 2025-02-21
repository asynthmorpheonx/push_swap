/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:26:03 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 00:09:25 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(t_list **stack_a, int i)
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
	if (i)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int i)
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
	if (i)
		write(1, "sb\n", 3);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_b)
	{
		temp1 = (*stack_b)->next;
		temp2 = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp1;
		(*stack_a)->next = temp2;
		if (i)
			write(1, "pa\n", 3);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*temp1;
	t_list	*temp2;

	if (*stack_a)
	{
		temp1 = (*stack_a)->next;
		temp2 = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp1;
		(*stack_b)->next = temp2;
		if (i)
			write(1, "pb\n", 3);
	}
}
