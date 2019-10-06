/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:00:16 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_macro.h"

# define FTPF_PA "$"
# define FTPF_FL "+- #0"
# define FTPF_TY "diouxXDOUeEfFgGaAcCsSpnb"
# define FTPF_LH "hlzjL"
# define PRC_NO (-2147483647)

typedef struct		s_formatph
{
	int				param;
	int				flags;
	int				fieldwidth;
	int				precision;
	int				length;
	int				type;
}					t_formatph;

size_t				ft_convert(char **buf, const char **format, t_formatph
					*forma, va_list ap);
size_t				ft_rpstr(char **buf, t_formatph forma, va_list ap);
#endif
