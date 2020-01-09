/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:42:45 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 09:25:53 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h> 

static void	pw_sort_three(t_pw_stack *stack)
{
	if (stack->a->val > stack->a->next->val &&
		stack->a->val < stack->a->next->next->val)
		run_command("sa", 1, stack);
	else if (stack->a->val > stack->a->next->next->val)
		run_command("ra", 1, stack);
}

static void	pw_sort_five(t_pw_stack *stack)
{
	if (stack->max_sort->sort < 3)
	{
		run_command("pb", 2, stack);
		pw_sort_three(stack);
	}
	else
		pw_st_a_to_b(stack);
	pw_st_b_to_a(stack);
	pw_st_a_min_to_top(stack);
}

static void	pw_sort_other(t_pw_stack *stack)
{
	pw_st_a_to_b(stack);
	pw_st_b_to_a(stack);
	pw_st_a_min_to_top(stack);
}

int			main(int ac, char **av)
{
	t_pw_stack	*stack;

	if (ac < 2)
	{
		printf("%7s./push_swap number\n%7s\
./push_swap first_number ... last_number\n",
				"usage: ", "");
		exit(0);
	}
	stack = pw_create_stack(ac, av);
	if (stack->a == NULL)
		exit(pw_stack_free(&stack), 0);
	stack->len_a = pw_get_len(stack->a);
	pw_set_norm(stack);
	if (stack->len_a == 3)
		pw_sort_three(stack);
	else if (stack->len_a == 5)
		pw_sort_five(stack);
	else
		pw_sort(stack);
	return (pw_stack_free(&stack, 0));
}
