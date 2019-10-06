/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:56:48 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array		*ft_arrnew(void)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * ARRAY_SIZE)))
		return (NULL);
	ret->max_size = ARRAY_SIZE;
	return (ret);
}

t_array		*ft_arrnew_size(size_t size)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * size)))
		return (NULL);
	ret->max_size = size;
	return (ret);
}

t_array		*ft_arrnew_arr(t_array *arr)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * arr->max_size)))
		return (NULL);
	ret->current_size = arr->current_size;
	ret->max_size = arr->max_size;
	ft_memcpy(ret->table, arr->table, sizeof(t_arritem) * arr->max_size);
	return (ret);
}
