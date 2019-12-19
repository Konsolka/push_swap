/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:42:45 by mburl             #+#    #+#             */
/*   Updated: 2019/12/19 15:14:45 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


int		check_sort(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (*(int *)lst->content > *(int *)lst->next->content)
				return (0);
			lst = lst->next;
		}
		return (1);
	}
}

int		check_rev_sort(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (*(int *)lst->content < *(int *)lst->next->content)
				return (0);
			lst = lst->next;
		}
		return (1);
	}
	return (-1);
}
int		command_to_exec(t_list *lst_a, t_list *lst_b)
{
	t_list	*temp;

	temp = lst_a;

	return (0);
}

void	sorting(t_list **lst_a, t_list **lst_b)
{
	while (check_sort(*lst_a) == 0)
	{
		if (*(int *)(*lst_a)->content > *(int *)(*lst_a)->next->content)
			run_swap(lst_a);
		0 3 2 4 1 5 9 8 7 6
		
	}
}

int		main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	t_data		data;
	int			temp;
	int			i;
	
	lst_a = NULL;
	lst_b = NULL;
	ac -= 1;
	data.size = ac;
	while (ac > 0)
	{
		i = 0;
		while (i < (int)ft_strlen(av[i]))
		{
			if (ft_isdigit(av[ac][i]))
				ft_exit("Error\n", lst_a, lst_b);
			i++;
		}
		temp = ft_atoi(av[ac]);
		ft_lstadd(&lst_a, ft_lstnew(&temp, sizeof(int)));
		ac--;
	}
	data.lst = lst_a;
	sorting(&lst_a, &lst_b);
	ft_exit("", lst_a, lst_b);
	return (0);
}
