/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:39:01 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = *alst;
		ft_lstdelone(&tmp, del);
		*alst = (*alst)->next;
	}
}
