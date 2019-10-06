/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:41:49 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_private.h"

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	char		*str;
	int			ret;

	str = 0;
	ret = ft_vasprintf(&str, format, ap);
	write(fd, str, ret);
	ft_strdel(&str);
	return (ret);
}

static size_t	ft_memjoin(char **s1, size_t n1, char *s2, size_t n2)
{
	char		*tmp;

	if (!s1 || !s2)
		return (0);
	if (n2 == 0)
	{
		return (n1);
	}
	if (n1 == 0)
	{
		*s1 = s2;
		return (n2);
	}
	if (!(tmp = ft_strnew(n1 + n2)))
		return (0);
	ft_memcpy(tmp, *s1, n1);
	ft_memcpy(tmp + n1, s2, n2);
	ft_strdel(s1);
	ft_strdel(&s2);
	*s1 = tmp;
	return (n1 + n2);
}

static void		pf_join(char **s, const char *format, const char *ptr,
		size_t *size)
{
	if (format > ptr)
		*size = ft_memjoin(s, *size, ft_strsub(ptr, 0, format - ptr),
						format - ptr);
}

int				ft_vasprintf(char **s, const char *format, va_list ap)
{
	t_formatph	forma;
	const char	*ptr;
	size_t		len_con;
	size_t		size;
	char		*rpstr;

	size = 0;
	ptr = format;
	while (1)
	{
		if (*format == '%')
		{
			pf_join(s, format, ptr, &size);
			len_con = ft_convert(&rpstr, &format, &forma, ap);
			size = ft_memjoin(s, size, rpstr, len_con);
			ptr = format;
		}
		else if (*format == 0)
		{
			pf_join(s, format, ptr, &size);
			return (size);
		}
		else
			format++;
	}
}
