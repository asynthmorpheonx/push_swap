/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:04:18 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 00:05:58 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_a(t_list **stack_a, int i)
{
	t_list	*head;

	if (*stack_a && (*stack_a)->next)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = head;
		head->next = NULL;
		if (i)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **stack_b, int i)
{
	t_list	*head;

	if (*stack_b && (*stack_b)->next)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = head;
		head->next = NULL;
		if (i)
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate_a(t_list **stack_a, int i)
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
		if (i)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_list **stack_b, int i)
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
		if (i)
			write(1, "rrb\n", 4);
	}
}
