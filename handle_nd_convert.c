/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nd_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:03:10 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/10 22:58:09 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s1, void *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	if (!s2)
		return ;
	free(s2);
}

long	*c_to_d(char **c_arg, int *index)
{
	long	*d_arg;
	int		i;

	i = 0;
	while (c_arg[i])
		i++;
	check_if_valid(c_arg);
	d_arg = malloc(sizeof(long) * i);
	if (!d_arg)
		return (NULL);
	i = 0;
	while (c_arg[i])
	{
		d_arg[i] = ft_atoi(c_arg[i]);
		if (d_arg[i] > 2147483647
			|| d_arg[i] < -2147483648)
		{
			ft_free(c_arg, d_arg);
			ft_perror();
		}
		i++;
	}
	ft_free(c_arg, NULL);
	*index = i;
	return (d_arg);
}

void	check_for_doubles(long *numbers, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < end - 1)
	{
		j = i + 1;
		while (j < end)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				ft_perror();
			}
			j++;
		}
		i++;
	}
}

long	*turn_it_into_int(char *arg, int *index)
{
	char	**c_arg;
	long	*numbers;

	c_arg = ft_split(arg, ' ');
	if (!c_arg)
		return (free(arg), NULL);
	free(arg);
	numbers = c_to_d(c_arg, index);
	check_for_doubles(numbers, *index);
	return (numbers);
}

int	check_if_sorted_already(long *array, int end)
{
	int	i;

	i = 0;
	while (i < end - 1)
	{
		if (!(array[i] < array[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
