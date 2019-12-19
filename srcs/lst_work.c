/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:23:09 by mburl             #+#    #+#             */
/*   Updated: 2019/12/19 12:29:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lst_free(t_list *lst)
{
	t_list	*temp;
	while (lst)
	{
		free(lst->content);
		lst->content = NULL;
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	ft_exit(char *str, t_list *lst, t_list *lst_b)
{
	ft_lst_free(lst);
	ft_lst_free(lst_b);
	ft_putstr_err(str);
}