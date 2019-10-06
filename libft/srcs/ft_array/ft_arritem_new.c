/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arritem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:46:36 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_arritem	ft_arritem_new(void *data, size_t size)
{
	t_arritem	ret;

	ft_bzero(&ret, sizeof(t_arritem));
	if (data && size != 0)
	{
		ret.content = data;
		ret.content_size = size;
	}
	return (ret);
}
