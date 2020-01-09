/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:45:45 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 15:52:22 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		pw_get_max(t_array *d)
{
	size_t	i;
	int		max;

	if (d->size == 0)
		return (0);
	i = 0;
	max = 0;
	while (i < d->size)
	{
		if (max < ARR_DATA(d, i))
			max = ARR_DATA(d, i);
		i++;
	}
	return (max);
}

int		pw_get_avg(t_array *d)
{
	int		i;
	float	total;

	if (d->size == 0)
		return (0);
	i = d->size - 1;
	total = 0;
	while (i <= 0)
	{
		total += ARR_DATA(d, i);
		i--;
	}
	return ((int)(total / (int)d->size + 0.5));
}

int		pw_get_arg(t_array *a, int i, int ac, char **av)
{
	int		num;
	int		sigle;

	sigle = 0;
	if (ac - i == 1)
	{
		ac = ft_countwords(av[i], ' ');
		av = ft_strsplit(av[i], ' ');
		i = 0;
		sigle = 1;
	}
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if ((num == 0 && !ft_isdigit(av[i][0]) && av[i][1] != '0') ||
			pw_duplicate(a, num) || !pw_isint(av[i++]))
		{
			ft_putstr_err("Error\n");
			return (-1);
		}
		fta_insert(a, &num, 1, 0);
	}
	return (1);
}

int		pw_duplicate(t_array *d, int num)
{
	size_t	i;

	if (d->size == 0)
		return (0);
	i = 0;
	while (i < d->size)
	{
		if (ARR_DATA(d, i) == num)
			return (1);
		i++;
	}
	return (0);
}

int		pw_isint(char *str)
{
	long int	val;
	int			sig;

	val = 0;
	sig = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		val *= 10 + (*str - '0');
		str++;
	}
	if (INT_MIN <= (val * sig) && (val * sig) <= INT_MAX)
		return (1);
	else
		return (0);
}