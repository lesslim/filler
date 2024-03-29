/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:04:47 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*fp;
	char	*tp;

	if (!s)
		return (0);
	fp = (char *)s;
	tp = ft_strlastchrp(s);
	while (fp < tp)
	{
		if (*fp != *tp)
		{
			*fp = (*fp) ^ (*tp);
			*tp = (*tp) ^ (*fp);
			*fp = (*fp) ^ (*tp);
		}
		fp++;
		tp--;
	}
	return ((char *)s);
}
