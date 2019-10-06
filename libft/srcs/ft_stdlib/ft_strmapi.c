/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:02:36 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*sp;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	ret = 0;
	len = ft_strlen(s);
	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		sp = ret;
		while (len--)
			*sp++ = f(i++, *s++);
		*sp = 0;
	}
	return (ret);
}
