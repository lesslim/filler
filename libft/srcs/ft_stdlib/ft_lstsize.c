/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:05:10 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *node)
{
	size_t	ret;

	ret = 0;
	if (!node)
		return (ret);
	while (node->next)
	{
		ret++;
		node = node->next;
	}
	return (ret + 1);
}
