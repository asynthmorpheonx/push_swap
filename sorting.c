/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:56:50 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/10 21:54:28 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_in_array(long *nbrs, int index)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (i < index)
	{
		j = i + 1;
		while (j < index)
		{
			if (nbrs[i] > nbrs[j])
			{
				temp = nbrs[i];
				nbrs[i] = nbrs[j];
				nbrs[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_in_b(long *array, t_list **a, t_list **b, int nbr_count)
{
	int	i;
	int	j;

	i = 0;
	if (nbr_count <= 100)
		j = nbr_count / 7;
	else
		j = nbr_count / 14;
	while (*a)
	{
		if ((*a)->nbr <= array[i])
		{
			push_b(a, b, 1);
			rotate_b(b, 1);
			i++;
			j++;
		}
		else if ((*a)->nbr <= array[j])
		{
			push_b(a, b, 1);
			i++;
			j++;
		}
		else
			rotate_a(a, 1);
	}
}

void	sort_b_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		if ((*b)->nbr < ft_lstlast(*b)->nbr)
		{
			reverse_rotate_b(b, 1);
			push_a(a, b, 1);
		}
		else
			push_a(a, b, 1);
	}
}
