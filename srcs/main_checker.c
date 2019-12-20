/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:01:00 by mburl             #+#    #+#             */
/*   Updated: 2019/12/20 16:43:04 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	check_stack(t_list *lst_a, t_list *lst_b)
{
	if (lst_b || !lst_a)
	{
		ft_putstr("KO\n");
		return ;
	}
	while (lst_a->next)
	{
		if (*(int *)lst_a->content > *(int *)lst_a->next->content)
		{
			ft_putstr("KO\n");
			return ;
		}
		lst_a = lst_a->next;
	}
	ft_putstr("OK\n");
}

void	run_commands(char *str, t_list **lst, t_list **lst_b)
{
	printf("\n===%s===\n", str);
	if (*str == 's')
	{
		if (*(str + 1) == 'a' || *(str + 1) == 'b')
			run_swap((*(str + 1) == 'a') ? lst : lst_b);
		else if (*(str + 1) == 's')
		{
			run_swap(lst);
			run_swap(lst_b);
		}
	}
	else if (*str == 'p')
	{
		if (*(str + 1) == 'a')
			run_push(lst_b, lst);
		else if (*(str + 1) == 'b')
			run_push(lst, lst_b);
		else
			ft_exit("Error\n", *lst, *lst_b);
	}
	else if (*str == 'r' && ft_strlen(str) == 2)
	{
		if (*(str + 1) == 'a' || *(str + 1) == 'b')
			run_line((*(str + 1) == 'a') ? lst : lst_b);
		else if (*(str + 1) == 'r')
		{
			run_line(lst);
			run_line(lst_b);
		}
	}
	else if (*str == 'r' && *(str + 1) == 'r' && ft_strlen(str) == 3)
	{
		if (*(str + 2) == 'a' || *(str + 2) == 'b')
			run_reverse((*(str + 2) == 'a') ? lst : lst_b);
		else if (*(str + 2) == 'r')
		{
			run_reverse(lst);
			run_reverse(lst_b);
		}
	}
	else
		ft_exit("Error", *lst, *lst_b);
}

void	ft_print(t_list *lst_a, t_list *lst_b)
{
	while (lst_a || lst_b)
	{
		if (lst_a && lst_b)
			if (lst_a->content && lst_b->content)
				printf("%d ---- %d\n", *(int *)lst_a->content, *(int *)lst_b->content);
		if (!lst_a && lst_b)
			if (lst_b->content)
				printf("%1s ---- %d\n", "", *(int *)lst_b->content);
		if ((!lst_b || !lst_b->content) &&lst_a)
			if (lst_a->content)
				printf("%d ---- %1s\n", *(int *)lst_a->content, "");
		if (lst_a)
			lst_a = lst_a->next;
		if (lst_b)
			lst_b = lst_b->next;
	}
}

void	reading_commands(t_list **lst, t_list **lst_b)
{
	char	*c;

	ft_print(*lst, *lst_b);
	while (get_next_line(0, &c) > 0)
	{
		run_commands(c, lst, lst_b);
		ft_print(*lst, *lst_b);
		free(c);
	}
}

int		main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			temp;
	int			i;
	
	lst_a = NULL;
	lst_b = NULL;
	ac -= 1;
	if (ac < 1)
	{
		printf("%7s./checker number\n%7s\
./checker first_number ... last_number\n", "usage: ", "");
		ft_exit("", lst_a, lst_b);
	}
	while (ac > 0)
	{
		i = 0;
		while (i < (int)ft_strlen(av[i]))
		{
			if ('0' < av[ac][i] && av[ac][i] > '9')
				ft_exit("Error\n", lst_a, lst_b);
			i++;
		}
		temp = ft_atoi(av[ac]);
		ft_lstadd(&lst_a, ft_lstnew(&temp, sizeof(int)));
		ac--;
	}
	reading_commands(&lst_a, &lst_b);
	check_stack(lst_a, lst_b);
	ft_lst_free(lst_a);
	ft_lst_free(lst_b);
	return (0);
}