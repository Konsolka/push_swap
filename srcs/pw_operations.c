/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:14:48 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 16:28:49 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pw_swap(t_array *d, t_array *dv, char *str)
{
	int		temp;
	
	(void)dv;
	if (d->size < 2)
		return ;
	temp = ARR_DATA(d, d->size - 2);
	ARR_DATA(d, d->size - 2) = ARR_DATA(d, d->size - 1);
	ARR_DATA(d, d->size - 1) = temp;
	ft_putstr(str);
	ft_putchar('\n');
}

void	pw_push(t_array *dst, t_array *src, char *str)
{
	int		temp;

	if (src->size == 0)
		return ;
	temp = ARR_DATA(src, src->size - 1);
	fta_popback(src, 1);
	fta_append(dst, &temp, 1);
	ft_putstr(str);
	ft_putchar('\n');
}

void	pw_rev_rotate(t_array *d, t_array *dv, char *str)
{
	int		temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARR_DATA(d, 0);
	fta_append(d, &temp, 1);
	fta_popindex(d, 0, 1);
	ft_putstr(str);
	ft_putchar('\n');
}

