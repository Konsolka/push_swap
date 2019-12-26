/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:51:45 by mburl             #+#    #+#             */
/*   Updated: 2019/12/26 12:21:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*hold_first(t_list *lst, int min, int max, int i, t_list *node)
{
	while (lst)
	{
		if (((i - 1) * (max / (min * 5)) < ARR_DATA(lst) && ARR_DATA(lst) < i * max / (min * 5)) && lst != node)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
