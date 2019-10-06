/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:57:24 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	flen;
	size_t	slen;

	if (!s1 || !s2)
		return (0);
	ret = 0;
	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	if ((ret = (char *)malloc(sizeof(char) * (flen + slen + 1))))
	{
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
