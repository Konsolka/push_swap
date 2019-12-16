/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:21 by mburl             #+#    #+#             */
/*   Updated: 2019/12/16 19:10:36 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
typedef struct	s_checker
{
	int					value;
	struct s_checker	*next;
	struct s_checker	*prev;
	
}				t_checker;

void	ft_exit(char *str, t_checker *lst, t_checker *lst_b);
void	ft_lst_checker_add(t_checker **lst, char *str);
void	ft_lst_begin(t_checker **lst);
void	run_sa(t_checker **lst);

#endif