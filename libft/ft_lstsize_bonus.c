/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:53:55 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/02/08 18:32:15 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list *head;
	
	head = lst;
	i = 0;
	if (lst != NULL)
	{
		while (lst != head)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
