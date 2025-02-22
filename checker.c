/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:29:06 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 01:03:22 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

t_list	*stor_in_list(long *nbrs, int end)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < end)
		ft_lstadd_back(&stack_a, ft_lstnew(nbrs[i++]));
	free(nbrs);
	return (stack_a);
}

int	check_if_sorted(t_list *a, t_list *b)
{
	long	last;

	if (b || !a)
		return (0);
	last = a->nbr;
	while (a)
	{
		if (last > a->nbr)
			return (0);
		last = a->nbr;
		a = a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	long	*nbrs;
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	i = 0;
	nbrs = turn_it_into_int(join_all(ac, av), &i);
	a = stor_in_list(nbrs, i);
	b = NULL;
	read_nd_do(&a, &b);
	if (!check_if_sorted(a, b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
