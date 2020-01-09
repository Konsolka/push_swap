/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_backtrack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:27:51 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 14:38:45 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pw_backtrack(t_array *a, t_array *b, int limit)
{
	while (ARR_DATA(a, a->size - 1) <= limit && 
		ARR_DATA(a, a->size - 1) != 1)
	{
		if (ARR_DATA(a, a->size - 1) == ARR_DATA(a, 0) + 1)
			pw_rotate(a, b, "ra");
		else
			pw_push(b, a, "pb");
	}
	if (pw_get_min(b) == ARR_DATA(a, 0) + 1)
		ft_push_swap(a, b);
}

void	pw_backtrack_split(t_array *a, t_array *b, int limit)
{
	int		c;
	int		i;
	int		avg;

	c = 0;
	avg = pw_get_avg_limit(a, limit);
	while (ARR_DATA(a, a->size - 1) <= limit &&
		ARR_DATA(a, a->size - 1) != 1)
	{
		if (ARR_DATA(a, a->size - 1) >= avg)
		{
			pw_rotate(a, b, "ra");
			c++;
		}
		else
			pw_push(b, a, "pb");
	}
	i = -1;
	while (++i < c)
		if (ARR_DATA(b, b->size - 1) != pw_get_max(b))
			pw_rev_rotate_r(a, b, "rrr");
		else
			pw_rev_rotate(a, b, "rra");
	if (pw_get_min(b) == ARR_DATA(a, 0) + 1 && c > 0)
		ft_push_swap(a, b);
}

void	ft_push_swap(t_array *a, t_array *b)
{
	int		max;

	if (b->size == 0)
		return ;
	max = pw_get_max(b);
	pw_split_to_a(a, b, pw_get_avg(b), b->size);
	while ((ARR_DATA(a, a->size - 1) == ARR_DATA(a, 0) + 1 ||
			ARR_DATA(a, a->size - 1) == 1) && !pw_sorted(a))
		pw_rotate(a, b, "ra");
	ft_push_swap(a, b);
	if (pw_get_len(a, max) >= 20)
		pw_backtrack_split(a, b, max);
	pw_backtrack(a, b, max);
}