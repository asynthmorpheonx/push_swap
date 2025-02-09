/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nd_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:51:16 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/09 18:47:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_emty(char *arg)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (arg[i])
	{
		if (arg[i] != ' ' && !(arg[i] >= 9 && arg[i] <= 13))
			toggle = 1;
		i++;
	}
	return (toggle);
}

int	valid_number(char *str)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 1;
	if (!check_if_emty(str))
		ft_perror();
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (toggle == 0)
				ft_perror();
			if ((str[i] == '-' || str[i] == '+' ) && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (ft_perror());
			else if (str[i] != ' ' && str[i] != '+' && str[i] != '-')
				return (ft_perror());
		}
		toggle = 0;
		i++;
	}
	return (1);
}

int	check_first(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!valid_number(av[i]))
			return (ft_perror());
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
	if (check_first(ac, av) == 0)
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

int sub_check(char *c_arg)
{
	int i;
	int len;
	int toggle;

	i = 0;
	len = 0;
	toggle = 1;
	while(c_arg[i])
	{
		if (c_arg[i] == '0' && toggle == 1)
		{
			while (c_arg[i] && !(c_arg[i] >= '1' && c_arg[i] <= '9'))
			{
				i++;
				toggle = 0;
			}
			i--;
		}
		if (c_arg[i] >= '1' && c_arg[i] <= '9')
			toggle = 0;
		len++;
		i++;
	}
	if (len > 11)
		return (-1);
	return (0);
}

void	check_if_valid(char **c_arg)
{
	int	i;

	i = 0;
	while (c_arg[i])
	{
		if (sub_check(c_arg[i]) == -1)
		{
			ft_free(c_arg, NULL);
			ft_perror();
		}
		i++;
	}
}
