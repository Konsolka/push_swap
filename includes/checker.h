/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:21 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 16:27:12 by mburl            ###   ########.fr       */
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
# define ARR_DATA(D, I) ((int *)(D)->data)[I]
# define NEW_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}
# define ARR_GET(A, I) (ARR_START(A) + ARR_OFFSET(A, I))
# define ARR_START(A) ((A)->data)
# define ARR_OFFSET(A, I) ((I) * ARR_STEP(A))
# define ARR_STEP(A) ((A)->type_size)
# define ARR_INIT_SIZE 16
# define ARR_FACTOR 2
# define ARR_END (A) ((A)->data + (A)->size * (A)->type_size)
# define MIN2(A, B) ((A) < (B) ? (A) : (B))

typedef	struct	s_mlx
{
	void	*win;
	void	*ptr;
}				t_mlx;

typedef struct	s_array
{
	void	*data;
	size_t	size;
	size_t	max;
	size_t	type_size;
}				t_array;

typedef struct	s_data
{
	int		size;
}				t_data;

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
int		check_sort(t_list *lst);
void	pw_split_to_b(t_array *a, t_array *b, int avg, int size);
void	pw_sortdata(t_array *v, int left, int right);
int		pw_sorted(t_array *v);
void	pw_rank(t_array *v, t_array *dv);
void	pw_backtrack(t_array *a, t_array *b, int limit);
void	pw_backtrack_split(t_array *a, t_array *b, int limit);
void	ft_push_swap(t_array *a, t_array *b);
int		pw_get_max(t_array *d);
int		pw_get_avg(t_array *d);
int		pw_get_arg(t_array *a, int i, int ac, char **av);
int		pw_duplicate(t_array *d, int num);
int		pw_isint(char *str);
int		fta_insert(t_array *self, void const *data, size_t datalen, size_t index);
void	fta_clear(t_array *self);
int		fta_resize(t_array *self, size_t new_size);
int		pw_get_len(t_array *d, int lim);
int		pw_get_avg_limit(t_array *d, int lim);
void	pw_merge(t_array *a, t_array *b);
int		pw_get_min(t_array *d);

#endif