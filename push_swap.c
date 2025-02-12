/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:48 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/10 23:22:31 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(-1);
	return(0);
}

t_list *stor_in_list(long *nbrs, int end)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < end)
		ft_lstadd_back(&stack_a, ft_lstnew(nbrs[i++]));
	return(stack_a);
}
void	print_stack(t_list *stack , char c)
{
	int	i;

	i = 0;
	printf("======================= stack %c =======================\n", c);
	while (stack)
	{
		printf("			[%ld]====>[%d]\n", stack->nbr, i);
		i++;
		stack = stack->next;
	}
	printf("=======================================================\n");
}

int main(int ac, char **av)
{
	int		i;
	long	*nbrs;
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	nbrs = turn_it_into_int(join_all(ac, av), &i);
	a = stor_in_list(nbrs, i);
	if (check_if_sorted_already(nbrs, i))
		return (0);
	sort_in_array(nbrs, i);
	b = NULL;
	sort_in_b(nbrs, &a, &b, i);
	sort_b_to_a(&a, &b);
	free(nbrs);
	ft_lstclear(&a);
}
