/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:09:33 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_asprintf(char **buf, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
int					ft_vasprintf(char **s, const char *format, va_list ap);
#endif
