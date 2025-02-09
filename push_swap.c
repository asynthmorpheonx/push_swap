/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:48 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/09 19:09:55 by mel-mouh         ###   ########.fr       */
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
	return(free(nbrs), stack_a);
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
	char	*arg;
	long	*nbrs;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		ft_perror();
	arg = join_all(ac, av);
	nbrs = turn_it_into_int(arg, &i);
	stack_a = stor_in_list(nbrs, i);
		
	stack_b = NULL;
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	push_b(&stack_a, &stack_b, 1);
	push_b(&stack_a, &stack_b, 1);
	reverse_rotate_both(&stack_a, &stack_b);
	
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
