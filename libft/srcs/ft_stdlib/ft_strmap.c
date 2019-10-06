/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:46:55 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*sp;
	size_t	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ret = 0;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		sp = ret;
		while (len--)
			*sp++ = f(*s++);
		*sp = 0;
	}
	return (ret);
}
