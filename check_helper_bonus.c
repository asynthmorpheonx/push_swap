/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:10:39 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 20:22:16 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	sub_check(char *c_arg)
{
	int	i;
	int	len;
	int	toggle;

	i = 0;
	len = 0;
	toggle = 1;
	while (c_arg[i++])
	{
		if (c_arg[i] == '0' && toggle == 1)
		{
			while (c_arg[i] && !(c_arg[i] >= '1' && c_arg[i] <= '9'))
			{
				i++;
				toggle = 0;
			}
			i++;
		}
		if (c_arg[i] >= '1' && c_arg[i] <= '9')
			toggle = 0;
		len++;
	}
	if (len > 11)
		return (0);
	return (1);
}

void	check_if_valid(char **c_arg)
{
	int	i;

	i = 0;
	while (c_arg[i])
	{
		if (!sub_check(c_arg[i]))
		{
			ft_free(c_arg, NULL);
			ft_perror();
		}
		i++;
	}
}
