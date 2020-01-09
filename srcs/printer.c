/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:15:51 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 10:39:10 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "checker.h"

void	draw()
{
	return ;
}

void	init_win()
{
	t_mlx	*data;

	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, WIDTH, HIEGHT, "PUSH_SWAP");
	
	mlx_loop(data->ptr);
}