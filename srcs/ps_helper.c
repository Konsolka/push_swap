/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:11:01 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 09:13:30 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack			*pw_create_new_node(int val)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*pw_get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int				pw_get_len(t_stack *st)
{
	int		i;

	i = 0;
	while (st)
	{
		st = st->next;
		i++;
	}
	return (i);
}

static void		pw_create_stack_a(int ac, char **av, t_pw_stack *sts)
{
	int		i;
	int		cur_val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			sts->flag_v = 1;
		else
		{
			cur_val = ft_atoi(av[i]);
			if (pw_is_valid(cur_val, av[i]) == 0 ||
				pw_is_not_dupl(sts->a, cur_val) == 0)
				pw_put_err(&sts, ft_free_arr(ac == 2 ? av : NULL, 1));
			if ((pw_stack_push_back(&sts->a, cur_val)) == NULL)
				pw_put_err(&sts, ft_free_arr(ac == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_arr(ac == 2 ? av : NULL, 1);
}

t_pw_stack		*pw_create_stack(int ac, char **av)
{
	t_pw_stack	*sts;

	if (!(sts = (t_pw_stack *)malloc(sizeof(t_pw_stack))))
		pw_put_err(&sts, 1);
	sts->a = NULL;
	sts->b = NULL;
	sts->flag_v = 0;
	pw_create_stack_a(ac, av, sts);
	return (sts);
}