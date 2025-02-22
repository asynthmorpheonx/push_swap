/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:26:03 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 01:09:32 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	push_a(t_list **stack_a, t_list **stack_b)
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
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
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
	}
}

void	rotate_a(t_list **stack_a)
{
	t_list	*head;

	if (*stack_a && (*stack_a)->next)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = head;
		head->next = NULL;
	}
}

void	rotate_b(t_list **stack_b)
{
	t_list	*head;

	if (*stack_b && (*stack_b)->next)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = head;
		head->next = NULL;
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
