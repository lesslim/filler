/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:52:08 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	pf_merge(t_array *arr, t_array *left, t_array *right, int (*cmp)
		(t_arritem *lhs, t_arritem *rhs))
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (int)left->current_size && j < (int)right->current_size)
	{
		if (cmp(left->table + i, right->table + j) > 0)
			arr->table[k++] = left->table[i++];
		else
			arr->table[k++] = right->table[j++];
	}
	while (i < (int)left->current_size)
		arr->table[k++] = left->table[i++];
	while (j < (int)right->current_size)
		arr->table[k++] = right->table[j++];
}

void	pf_mergesort(t_array *arr, int nbr, int (*cmp)
		(t_arritem *lhs, t_arritem *rhs))
{
	int			mid;
	t_array		*left;
	t_array		*right;

	mid = (nbr - 1) / 2;
	if (nbr < 2 || !(left = ft_arrsub(arr, 0, mid)) ||
		!(right = ft_arrsub(arr, mid + 1, nbr - 1)))
		return ;
	pf_mergesort(left, left->current_size, cmp);
	pf_mergesort(right, right->current_size, cmp);
	pf_merge(arr, left, right, cmp);
	ft_arrdel(&left);
	ft_arrdel(&right);
}

void	ft_arrmsort(t_array *arr, int (*cmp)(t_arritem *lhs,
		t_arritem *rhs))
{
	if (!arr || !cmp || arr->current_size <= 1)
		return ;
	pf_mergesort(arr, arr->current_size, cmp);
}
