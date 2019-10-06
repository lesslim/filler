/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 21:08:43 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arr_realloc(t_array *arr)
{
	t_arritem		*tmp;

	if (!arr || !(tmp = ft_memalloc(sizeof(t_arritem) * arr->max_size * 2)))
		return (FUN_FAIL);
	ft_memcpy(tmp, arr->table, sizeof(t_arritem) * arr->max_size);
	ft_memdel((void **)&(arr->table));
	arr->table = tmp;
	arr->max_size *= 2;
	return (FUN_SUCS);
}
