/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:21 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 09:20:01 by mburl            ###   ########.fr       */
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
# define ARR_DATA_A(D) (D)->a->val
typedef	struct	s_mlx
{
	void	*win;
	void	*ptr;
}				t_mlx;

typedef struct	s_stack
{
	int				val;
	int				i;
	int				sort;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_pw_stack
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*max_sort;
	int			len_a;
	int			len_b;
	int			opt_a;
	int			opt_b;
	int			opt_pl;
	int			temp_a;
	int			temp_b;
	int			temp_pl;
	int			print;
	int			flag_v;
}				t_pw_stack;

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
void	ft_lst_free(t_list *lst);
int		pw_stack_size(t_list *lst);
t_list	*find_smallest_num(t_list *lst);
void	find_min_max(t_list *lst, int *min, int *max);
t_pw_stack		*pw_create_stack(int ac, char **av);
int				pw_get_len(t_stack *st);
t_stack			*pw_get_last_node(t_stack *st);
t_stack			*pw_create_new_node(int val);

#endif