/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrremove_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:29:31 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_arritem	*ft_arrremove_at(t_array *arr, int index)
{
	t_arritem	tmp;
	t_arritem	*ret;

	if (!arr || (int)arr->current_size <= 0 || index < 0 ||
			index > (int)arr->current_size)
		return (NULL);
	if (index == (int)arr->current_size - 1)
	{
		arr->current_size--;
		ret = arr->table + index;
	}
	else
	{
		tmp = arr->table[index];
		ft_memmove(arr->table + index, arr->table + index + 1,
				sizeof(t_arritem) * (arr->current_size - index));
		arr->table[arr->current_size - 1] = tmp;
		ret = arr->table + arr->current_size - 1;
		arr->current_size--;
	}
	return (ret);
}
