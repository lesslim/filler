/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:10:43 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arrswap(t_array *arr, int index1, int index2)
{
	t_arritem	tmp;

	if (!arr || index1 < 0 || index2 < 0 || index1 >= (int)arr->current_size
			|| index2 >= (int)arr->current_size)
		return (FUN_FAIL);
	if (index1 != index2)
	{
		tmp = arr->table[index1];
		arr->table[index1] = arr->table[index2];
		arr->table[index2] = tmp;
	}
	return (FUN_SUCS);
}
