/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:42:45 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 16:14:26 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h> 

static	void	ft_pw_backtrack(t_array *a, t_array *b)
{
	if (pw_sorted(a))
		return ;
	pw_split_to_b(a, b, pw_get_avg(a), a->size);
	ft_push_swap(a, b);
	if (pw_get_len(a, pw_get_max(a)) >= 20)
	{
		pw_backtrack_split(a, b, pw_get_max(a));
		pw_backtrack_split(a, b, pw_get_max(a));
	}
	pw_backtrack(a, b, pw_get_max(a));
}

int		main(int ac, char **av)
{
	int		i;
	t_array	a;
	t_array	b;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	if (ac > 1)
	{
		i = 1;
		if (pw_get_arg(&a, i, ac, av) == -1)
		{
			fta_clear(&a);
			return (0);
		}
		pw_get_arg(&b, i, ac, av);
		pw_sortdata(&b, 0, b.size - 1);
		pw_rank(&a, &b);
		if (a.size <= 5)
			pw_simple(&a, &b);
		else
			ft_pw_backtrack(&a, &b);
		fta_clear(&a);
		fta_clear(&b);
	}
}