/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:17:53 by mburl             #+#    #+#             */
/*   Updated: 2019/12/19 12:27:59 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	run_swap(t_list **lst)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)->next = temp;
	}
}

void	run_push(t_list **lst, t_list **lst_b)
{
	t_list *temp;

	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = *lst_b;
		*lst_b = temp;
	}
}

void	run_reverse(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		while (temp->next->next)
			temp = temp->next;
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
		temp->next = *lst;
		*lst = temp;
	}
}

void	run_line(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->next;
		temp2 = *lst;
		temp3 = *lst;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp3;
		temp2->next->next = NULL;
		*lst = temp;
	}
}
