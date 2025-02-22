/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_join_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:51:16 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/22 01:12:50 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	check_if_emty(char *arg)
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

static int	valid_number(char *str)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 1;
	check_if_emty(str);
	while (str[i])
	{
		if (str[i] == ' ')
			toggle = 1;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if ((str[i] == '-' || str[i] == '+')
				&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
			else if ((str[i] == '+' || str[i] == '-') && toggle == 0)
				return (0);
			else if (str[i] != '+' && str[i] != '-' && str[i] != ' ')
				return (0);
		}
		else
			toggle = 0;
		i++;
	}
	return (1);
}

static int	check_first(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!valid_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*join_all(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	*temp2;

	i = 1;
	str = NULL;
	temp2 = NULL;
	if (!check_first(ac, av))
		ft_perror();
	while (i < ac)
	{
		temp = ft_strjoin(av[i], " ");
		if (str)
			temp2 = str;
		str = ft_strjoin(str, temp);
		if (temp2)
			free(temp2);
		free(temp);
		i++;
	}
	return (str);
}
