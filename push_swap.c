/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:48 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 00:51:09 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	return (stack_a);
}

void	check_if_emty(char *arg)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (arg[i])
	{
		if (arg[i] != ' ')
			toggle = 1;
		i++;
	}
	if (toggle)
		return ;
	ft_perror();
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
	if (check_if_sorted_already(nbrs, i))
		return (free(nbrs), 0);
	a = stor_in_list(nbrs, i);
	b = NULL;
	if (i <= 5)
		sort_pair(&a, &b, i);
	else
	{
		sort_in_array(nbrs, i);
		sort_in_b(nbrs, &a, &b, i);
		sort_b_to_a(&a, &b);
	}
	free(nbrs);
	ft_lstclear(&a);
	return (0);
}
