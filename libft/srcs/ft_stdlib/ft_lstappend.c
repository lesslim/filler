/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:50:56 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *node)
{
	t_list	*nnode;
	t_list	*lstp;

	nnode = ft_lstnew(node->content, node->content_size);
	lstp = *alst;
	if (!alst || !nnode)
		return ;
	if (!(*alst))
	{
		*alst = nnode;
		return ;
	}
	while (lstp->next)
		lstp = lstp->next;
	lstp->next = nnode;
}
