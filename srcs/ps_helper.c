/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:11:01 by mburl             #+#    #+#             */
/*   Updated: 2019/12/26 14:01:33 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		pw_stack_size(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*find_smallest_num(t_list *lst)
{
	t_list	*node;
	int		temp;

	temp = INT_MAX;
	node = ft_lstnew(&temp, sizeof(int));

	while (lst)
	{
		if (ARR_DATA(node) > ARR_DATA(lst))
			node = lst;
		lst = lst->next;
	}
	return (node);
}

void	find_min_max(t_list *lst, int *min, int *max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	while (lst)
	{
		if (ARR_DATA(lst) > *max)
			*max = ARR_DATA(lst);
		if (ARR_DATA(lst) < *min)
			*min = ARR_DATA(lst);
		lst = lst->next;
	}
}