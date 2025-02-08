/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:48 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/07 19:05:18 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return(0);
}

t_list *stor_in_list(long *nbrs, int end)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < end)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(nbrs[i]));
		i++;
	}
	return(free(nbrs), stack_a);
}
void	print_stack(t_list *stack)
{
	int	i;

	i = 0;
	printf("======================= stack A =======================\n");
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
	char	*arg;
	long	*nbrs;
	t_list	*stack_a;
	int		i;

	if (ac < 2)
		ft_perror();
	arg = join_all(ac, av);
	nbrs = turn_it_into_int(arg, &i);
	stack_a = stor_in_list(nbrs, i);
	print_stack(stack_a);
	ft_lstclear(&stack_a);
}
