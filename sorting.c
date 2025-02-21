/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:56:50 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 00:48:14 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_in_array(long *nbrs, int index)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (i < index - 1)
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

static int	which_index(int nbr_count)
{
	if (nbr_count <= 100)
		return (nbr_count / 7);
	return (nbr_count / 13);
}

void	sort_in_b(long *array, t_list **a, t_list **b, int nbr_count)
{
	int	i;
	int	j;

	i = 0;
	j = which_index(nbr_count);
	while (*a)
	{
		if ((*a)->nbr <= array[i] || ((*a)->nbr <= array[j]))
		{
			if ((*a)->nbr <= array[i])
			{
				push_b(a, b, 1);
				rotate_b(b, 1);
			}
			else
				push_b(a, b, 1);
			i++;
			if (j < nbr_count - 1)
				j++;
		}
		else
			rotate_a(a, 1);
	}
}

static int	return_biggest(t_list *b)
{
	int		i;
	int		j;
	long	biggest;

	i = 0;
	j = 0;
	biggest = b->nbr;
	while (b)
	{
		if (b->nbr > biggest)
		{
			j = i;
			biggest = b->nbr;
		}
		b = b->next;
		i++;
	}
	return (j);
}

void	sort_b_to_a(t_list **a, t_list **b)
{
	int	beggest;

	while (*b)
	{
		beggest = return_biggest(*b);
		if (beggest == 0)
			push_a(a, b, 1);
		else if (beggest <= (ft_lstsize(*b) / 2))
		{
			while (return_biggest(*b) != 0)
				rotate_b(b, 1);
		}
		else if (beggest > (ft_lstsize(*b) / 2))
		{
			while (return_biggest(*b) != 0)
				reverse_rotate_b(b, 1);
		}
	}
}
