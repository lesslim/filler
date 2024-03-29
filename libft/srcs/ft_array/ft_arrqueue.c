/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:16:47 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int			ft_arrqueue_push(t_array *queue, t_arritem *item)
{
	if (!queue || !item)
		return (FUN_FAIL);
	return (ft_arrappend(queue, item));
}

t_arritem	*ft_arrqueue_pop(t_array *queue)
{
	if (!queue || queue->current_size == 0)
		return (NULL);
	return (ft_arrremove_at(queue, 0));
}

t_arritem	*ft_arrqueue_peek(t_array *queue)
{
	if (!queue || queue->current_size == 0)
		return (NULL);
	return (ft_arritem_at(queue, 0));
}
