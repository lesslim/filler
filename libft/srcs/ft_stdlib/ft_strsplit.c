/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:39:52 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:24 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		pft_count_word(char const *s, char c)
{
	int			counted;
	int			ret;

	counted = 0;
	ret = 0;
	while (*s)
	{
		if (*s != c && !counted)
		{
			ret++;
			counted = 1;
		}
		if (*s == c && counted)
			counted = 0;
		s++;
	}
	return (ret);
}

static char		*pft_next_word(char const **s, char c)
{
	char const	*tp;
	char		*ret;

	while (**s == c)
		(*s)++;
	tp = *s;
	while (*tp && *tp != c)
		tp++;
	ret = ft_strsub(*s, 0, tp - *s);
	*s = tp;
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	char		**tp;
	int			word_count;

	if (!s)
		return (0);
	ret = 0;
	word_count = pft_count_word(s, c);
	if ((ret = (char **)malloc(sizeof(char *) * (word_count + 1))))
	{
		tp = ret;
		while (word_count--)
			*tp++ = pft_next_word(&s, c);
		*tp = 0;
	}
	return (ret);
}
