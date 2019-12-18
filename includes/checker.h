/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:21 by mburl             #+#    #+#             */
/*   Updated: 2019/12/18 19:07:00 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
typedef struct	s_checker
{
	void				*content;
	size_t				content_size;
	struct s_checker	*next;
	struct s_checker	*prev;
	
}				t_checker;

void	ft_exit(char *str, t_list *lst, t_list *lst_b);
void	ft_lst_checker_add(t_list **lst, char *str, size_t content_size);
void	ft_lst_begin(t_list **lst);
void	run_swap(t_list **lst);
void	run_push(t_list **lst, t_list **lst_b);
void	run_reverse(t_list **lst);

#endif