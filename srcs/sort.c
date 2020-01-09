/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:28:28 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 09:31:12 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pw_st_a_norm(t_pw_stack *stack)
{
	int		com;

	pw_set_index(stack->a);
	stack->max_sort = pw_get_max_sort(stack->a);
	stack->len_a = pw_get_len(stack->a);
	com = stack->len_a - stack->max_sort->i - stack->max_sort->sort > 0 ? 
		stack->len_a - (stack->len_a - stack->max_sort
}