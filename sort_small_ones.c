/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_ones.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:44:10 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/20 15:02:20 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_smallest(t_list *a)
{
	int		i;
	int		j;
	long	smallest;

	i = 0;
	j = 0;	
	smallest = a->nbr;
	while (a)
	{
		if (a->nbr < smallest)
		{
			smallest = a->nbr;
			j = i;
		}
		i++;
		a = a->next;
	}
	return (j);
}

static void	small_sort_comlpex(t_list **a)
{
	t_list *first;
	t_list *second;
	t_list *third;

	first = *a;
	second = (*a)->next;
	third = second->next;
	if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr < third->nbr)
		swap_a(a, 1);
	else if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
		rotate_a(a, 1);
	if (first->nbr > second->nbr && second->nbr > third->nbr)
	{
		swap_a(a, 1);
		reverse_rotate_a(a, 1);
	}
	else if (first->nbr < second->nbr && first->nbr < third->nbr && second->nbr > third->nbr)
	{
		reverse_rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if (first->nbr < second->nbr && first->nbr > third->nbr)
		reverse_rotate_a(a, 1);
}

static void	push_th_small(t_list **a, t_list **b)
{
	int	smallest;

	while (*a)
	{
		smallest = return_smallest(*a);
		if (smallest == 0)
		{
			push_b(a, b, 1);
			return ;
		}
		else if (smallest <= (ft_lstsize(*a) / 2))
		{
			while (return_smallest(*a) != 0	)
				rotate_a(a, 1);
		}
		else if (smallest > (ft_lstsize(*a) / 2))
		{
			while (return_smallest(*a) != 0)
				reverse_rotate_a(a, 1);			
		}
	}
}

void    sort_pair(t_list **a, t_list **b, int i)
{
	if (i == 2)
		swap_a(a, 1);
    else if (i == 3)
		small_sort_comlpex(a);
	else if (i == 4)
	{
		push_th_small(a, b);
		small_sort_comlpex(a);
		push_a(a, b, 1);
	}
	else if (i == 5)
	{
		push_th_small(a, b);
		push_th_small(a, b);
		small_sort_comlpex(a);
		if ((*b)->nbr < (*b)->next->nbr)
			swap_b(b, 1);
		push_a(a, b, 1);
		push_a(a, b, 1);
	}
}
