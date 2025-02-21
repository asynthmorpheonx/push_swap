/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:29:06 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/21 23:43:22 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

t_list *stor_in_list(long *nbrs, int end)
{
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < end)
		ft_lstadd_back(&stack_a, ft_lstnew(nbrs[i++]));
	free(nbrs);
	return(stack_a);
}

void	print_stack(t_list *stack , char c)
{
	int	i;

	i = 0;
	printf("======================= stack %c =======================\n", c);
	while (stack)
	{
		printf("		      [%ld]====>[%d]\n", stack->nbr, i);
		i++;
		stack = stack->next;
	}
	printf("=======================================================\n");
}

int	check_if_instruction(char	*str)
{
	if ((ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0) || (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0))
		return (1);
	else if ((ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0) || (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0))
		return (1);
	else if ((ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0) || (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0))
		return (1);
	else if ((ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0))
		return (1);
	return (0);
}

void	user_sort_execution(char *instruction, t_list **a, t_list **b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse_rotate_a(a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse_rotate_b(b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		reverse_rotate_both(a, b);
}

void	read_nd_do(t_list **a, t_list **b)
{
	char *line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !check_if_instruction(line))
		{
			if (!check_if_instruction(line))
				write(1, "Error\n", 6);
			if (line)
				free(line);
			break ;
		}
		if (check_if_instruction(line))
			user_sort_execution(line, a, b);
	}
	get_next_line(-1);
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

int main(int ac, char **av)
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