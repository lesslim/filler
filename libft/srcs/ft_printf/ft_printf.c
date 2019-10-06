/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:08:56 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_private.h"

/*
** printf function
*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ret);
}

/*
**write printf string to file descriptor fd.
*/

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

/*
**write printf string to string buffer.
*/

int		ft_asprintf(char **buf, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vasprintf(buf, format, ap);
	va_end(ap);
	return (ret);
}
