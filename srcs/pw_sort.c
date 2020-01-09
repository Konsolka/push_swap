/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:06:19 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 14:15:09 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pw_rank(t_array *v, t_array *dv)
{
	int		i;
	int		j;

	i = (int)v->size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < (int)dv->size - 1)
		{
			if (ARR_DATA(v, i) == ARR_DATA(dv, (int)dv->size - 1 - j) &&
				ARR_DATA(dv, (int)dv->size - 1 - j) != 999999)
			{
				ARR_DATA(dv, (int)dv->size - 1 - j) = 999999;
				break ;
			}
			j++;
		}
		ARR_DATA(v, i) = j + 1;
		i--;
	}
	fta_clear(dv);
	*dv = NEW_ARRAY(int);
}

static int	pw_part_array(t_array *v, int left, int right, int pivot)
{
	int		temp;

	while (left <= right)
	{
		while (ARR_DATA(v, left) > pivot)
			left++;
		while (ARR_DATA(v, right) < pivot)
			right--;
		if (left <= right)
		{
			temp = ARR_DATA(v, right);
			ARR_DATA(v, right) = ARR_DATA(v, left);
			ARR_DATA(v, left) = temp;
			left++;
			right--;
		}
	}
	return (left);
}

void	pw_sortdata(t_array *v, int left, int right)
{
	int		pivot;
	int		index;

	if (left >= right)
		return ;
	pivot = ARR_DATA(v, (right + left) / 2);
	index = pw_part_array(v, left, right, pivot);
	pw_sortdata(v, left, index - 1);
	pw_sortdata(v, index, right);
}

int		pw_sorted(t_array *v)
{
	int		i;

	if (v->size == 0)
		return (1);
	i = v->size - 1;
	while (i > 0)
	{
		if (ARR_DATA(v, i - 1) < ARR_DATA(v, i))
			return (0);
		i--;
	}
	return (1);
}