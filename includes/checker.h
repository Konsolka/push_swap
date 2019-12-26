/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:21 by mburl             #+#    #+#             */
/*   Updated: 2019/12/26 14:20:45 by mburl            ###   ########.fr       */
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

# define WIDTH 500
# define HIEGHT 1000
# define ARR_DATA(D) *(int *)(D)->content

typedef	struct	s_mlx
{
	void	*win;
	void	*ptr;
}				t_mlx;

typedef struct	s_stack
{
	int		data;
	int		w;
}				t_stack;

typedef struct	s_check
{
	t_stack		*la;
	t_stack		*lb;
	char		**ar;
	int			fd;
	int			len;
	int			vis;
}				t_check;

void	ft_exit(char *str, t_list *lst, t_list *lst_b);
void	ft_lst_checker_add(t_list **lst, char *str, size_t content_size);
void	ft_lst_begin(t_list **lst);
void	run_swap(t_list **lst);
void	run_push(t_list **lst, t_list **lst_b);
void	run_reverse(t_list **lst);
void	run_line(t_list **lst);
void	ft_lst_data_add(t_data **data, t_list *lst);
void	ft_lst_free(t_list *lst);
int		pw_stack_size(t_list *lst);
t_list	*find_smallest_num(t_list *lst);
void	find_min_max(t_list *lst, int *min, int *max);
t_list	*hold_first(t_list *lst, int min, int max, int i, t_list *node);

#endif