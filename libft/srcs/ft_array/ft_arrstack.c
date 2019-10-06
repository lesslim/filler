/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:58:59 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int			ft_arrstack_push(t_array *stack, t_arritem *item)
{
	if (!stack || !item)
		return (FUN_FAIL);
	return (ft_arrappend(stack, item));
}

t_arritem	*ft_arrstack_pop(t_array *stack)
{
	if (!stack || stack->current_size == 0)
		return (NULL);
	return (ft_arrremove_at(stack, stack->current_size - 1));
}

t_arritem	*ft_arrstack_peek(t_array *stack)
{
	if (!stack || stack->current_size == 0)
		return (NULL);
	return (ft_arritem_at(stack, stack->current_size - 1));
}
