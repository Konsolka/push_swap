/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:53:40 by mburl             #+#    #+#             */
/*   Updated: 2020/01/09 16:26:20 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		fta_insert(t_array *self, void const *data, size_t datalen, size_t index)
{
	if (self->size < index || fta_reserve(self, datalen))
		return (1);
	ft_memmove(ARR_GET(self, index + datalen), ARR_GET(self, index),
				ARR_OFFSET(self, self->size - index));
	ft_memcpy(ARR_GET(self, index), data, ARR_OFFSET(self, datalen));
	self->size += datalen;
	return (0);
}

void	fta_clear(t_array *self)
{
	if (self->max > 0)
	{
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}

int		fta_reserve(t_array *self, size_t size)
{
	const size_t	total_size = size + self->max;
	size_t			new_size;

	if (total_size > self->max)
	{
		new_size = (self->max > 0 ? self->max : ARR_INIT_SIZE);
		while (new_size < total_size)
			new_size *= ARR_FACTOR;
		return (fta_resize(self, new_size));
	}
	return (0);
}

int		fta_resize(t_array *self, size_t new_size)
{
	void	*temp;

	temp = malloc(new_size * self->type_size);
	if (temp == NULL)
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(temp, self->data, self->size * self->type_size);
	free(self->data);
	self->data = temp;
	self->max = new_size;
	return (0);
}

void	fta_popback(t_array *self, size_t len)
{
	self->size -= MIN2(len, self->size);
}

int		fta_append(t_array *self, void const *data, size_t datalen)
{
	if (fta_reserve(self, datalen))
		return (1);
	ft_memcpy(ARR_END(self), data, ARR_OFFSET(self, datalen));
	self->size += datalen;
	return (0);
}