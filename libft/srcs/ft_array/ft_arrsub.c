/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:15:31 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array		*ft_arrsub(t_array *arr, int start, int end)
{
	t_array	*ret;

	if (!arr || start < 0 || start >= (int)arr->current_size || end < 0 ||
		end >= (int)arr->current_size || start > end ||
		!(ret = ft_arrnew_size(end - start + 1)))
		return (NULL);
	ret->current_size = end - start + 1;
	ft_memcpy(ret->table, arr->table + start, sizeof(t_arritem) *
			(ret->current_size));
	return (ret);
}
