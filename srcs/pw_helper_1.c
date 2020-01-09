/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:37:20 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 15:43:18 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		pw_get_min(t_array *d)
{
	size_t	i;
	int		min;

	if (d->size == 0)
		return (0);
	i = 0;
	min = ARR_DATA(d, i);
	while (i < d->size)
	{
		if (min > ARR_DATA(d, i))
			min = ARR_DATA(d, i);
		i++;
	}
	return (min);
}

int		pw_get_len(t_array *d, int lim)
{
	int		i;

	if (d->size == 0)
		return (0);
	i = 0;
	while (ARR_DATA(d, (int)d->size - 1 - i) <= lim && 
			ARR_DATA(d, (int)d->size - 1 - i) != 1)
		i++;
	return (i);
}

int		pw_get_avg_limit(t_array *d, int lim)
{
	int		i;
	float	total;

	if (d->size == 0)
		return (0);
	i = 0;
	total = 0.0;
	while (ARR_DATA(d, (int)d->size - 1 - i) <= lim &&
			ARR_DATA(d, (int)d->size - 1 - i) != 1)
	{
		total += ARR_DATA(d, (int)d->size - 1 - i);
		i++;
	}
	return ((int)(total / i + 0.5));
}

void	pw_merge(t_array *a, t_array *b)
{
	while (b->size > 0)
		pw_push(a, b, "pa");
}
