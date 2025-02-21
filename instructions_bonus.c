/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:26:03 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/21 21:57:38 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	swap_a(t_list **stack_a)
{
	t_list *current;
	t_list *temp;

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
	t_list *current;
	t_list *temp;

	if (*stack_b && (*stack_b)->next)
	{
		current = *stack_b;
		temp = (*stack_b)->next->next;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = current;
		current->next = temp;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
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
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
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
	}
}

void	rotate_a(t_list **stack_a)
{
	t_list *head;

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
	t_list *head;

	if (*stack_b && (*stack_b)->next)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstlast(*stack_b)->next = head;
		head->next = NULL;
	}
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

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
		temp1 =  *stack_b;
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

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}