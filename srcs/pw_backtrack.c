/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:36:02 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 16:29:18 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pw_sm_rotate(t_array *a, t_array *b)
{
	int		i;

	i = -1;
	while (++i < (int)a->size)
		if (ARR_DATA(a, i) == pw_get_max(a))
			break ;
	if (i <= (int)a->size / 2)
		pw_rev_rotate(a, b, "rrb");
	else
		pw_rotate(a, b, "rb");
}

void	pw_get_max_to_a(t_array *a, t_array *b)
{
	if (pw_get_max(b) == ARR_DATA(b, b->size - 1))
		pw_push(a, b, "pa");
	else
	{
		if (ARR_DATA(b, b->size - 1) == ARR_DATA(a, 0) + 1 ||
			ARR_DATA(b, b->size - 1) == 1)
		{
			pw_push(a, b, "pa");
			pw_rotate(a, b, "ra");
		}
		else
			pw_sm_rotate(b, a);
	}
}

void	pw_split_to_a(t_array *a, t_array *b, int avg, int size)
{
	while (size-- > 0)
	{
		if (b->size < 13)
			pw_get_max_to_a(a, b);
		else
		{
			if (avg <= ARR_DATA(b, b->size - 1))
			pw_push(a, b, "pa");
			else
			{
				if (ARR_DATA(b, b->size - 1) == ARR_DATA(a, 0) + 1 ||
					ARR_DATA(b, b->size - 1) == 1)
				{
					pw_push(a, b, "pa");
					pw_rotate(a, b, "ra");
				}
				else
					pw_rotate(b, a, "rb");
			}
		}
	}
}

void	pw_split_to_b(t_array *a, t_array *b, int avg, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (avg > ARR_DATA(a, a->size - 1))
			pw_push(b, a, "pb");
		else
			pw_rotate(a, b, "ra");
		i++;
	}
}
