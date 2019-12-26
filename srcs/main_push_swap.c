/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:42:45 by mburl             #+#    #+#             */
/*   Updated: 2019/12/26 14:19:39 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h> 

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
	return (-1);
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
int		sorting_h(t_list *lst_a, t_list *lst_b)
{
	

	return (0);
}

int		sorting(t_list **lst_a, t_list **lst_b, t_data data)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*temp;
	int		max;
	int		min;

	if (check_sort(*lst_a))
		return (0);
	temp = *lst_a;
	max = INT_MIN;
	min = INT_MAX;
	while (temp)
	{
		if (max < ARR_DATA(temp))
			max = ARR_DATA(temp);
		if (min > ARR_DATA(temp))
			min = ARR_DATA(temp);
		temp = temp->next;
	}
	while (check_sort(*lst_a) != 1)
	{
		while (*lst_a)
		{
			if (*lst_b)
			{
				if (ARR_DATA(*lst_a) < ARR_DATA(*lst_b))
					break ;
			}
			run_push(lst_a, lst_b);
			ft_putstr("pb\n");
		}
		temp = *lst_a;
		if (*lst_b && (*lst_b)->next && ARR_DATA(*lst_b) == max)
		{
			run_line(lst_b);
			ft_putstr("rb\n");
		}
		while (*lst_a && ARR_DATA(*lst_a) < ARR_DATA(*lst_b))
		{
			run_line(lst_a);
			ft_putstr("ra\n");
			if (*lst_a == temp);
				break ;
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			temp;
	int			i;
	int			runs;

	runs = 0;
	lst_a = NULL;
	lst_b = NULL;
	ac -= 1;
	if (ac < 1)
	{
		printf("%7s./push_swap number\n%7s\
./push_swap first_number ... last_number\n",
				"usage: ", "");
		ft_exit("", lst_a, lst_b);
	}
	data.size = ac;
	while (ac > 0)
	{
		i = 0;
		while (i < (int)ft_strlen(av[ac]))
		{
			if (!ft_isdigit(av[ac][i]))
				ft_exit("Error\n", lst_a, lst_b);
			i++;
		}
		temp = ft_atoi(av[ac]);
		ft_lstadd(&lst_a, ft_lstnew(&temp, sizeof(int)));
		ac--;
	}
	data.lst = lst_a;
	// data.size = pw_stack_size(lst_a);
	if (sorting(&lst_a, &lst_b, data))
	{
		run_reverse(&lst_b);
		ft_putstr("rrb\n");
		run_push(&lst_a, &lst_b);
		ft_putstr("pb\n");
		run_line(&lst_b);
		ft_putstr("rb\n");
	}
	while (lst_b)
	{
		run_push(&lst_b, &lst_a);
		ft_putstr("pa\n");
	}
	while (check_sort(lst_a) != 1)
	{
		run_reverse(&lst_a);
		ft_putstr("rra");
	}
	ft_exit("", lst_a, lst_b);
	return (0);
}
