/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_nd_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:03:48 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 14:33:41 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	check_if_instruction(char	*str)
{
	if ((ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0))
		return (1);
	else if ((ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0))
		return (1);
	else if ((ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		|| (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0))
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
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !check_if_instruction(line))
		{
			if (!check_if_instruction(line))
			{
				free(line);
				ft_lstclear(a);
				ft_lstclear(b);
				get_next_line(-1);
				ft_perror();
			}
			if (line)
				free(line);
			break ;
		}
		if (check_if_instruction(line))
			user_sort_execution(line, a, b);
		free(line);
	}
	get_next_line(-1);
}
