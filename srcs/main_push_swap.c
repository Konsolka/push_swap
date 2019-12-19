/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:42:45 by mburl             #+#    #+#             */
/*   Updated: 2019/12/19 13:01:50 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	int			temp;
	int			i;
	
	lst_a = NULL;
	lst_b = NULL;
	ac -= 1;
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
	ft_exit("", lst_a, lst_b);
	return (0);
}
