/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 21:42:40 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:17:39 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "ft_printf_private.h"

void			ft_scanflag(const char **format_ptr, t_formatph *forma);
void			ft_scan_width(const char **format_ptr,
				t_formatph *forma, va_list ap);
void			ft_scan_precision(const char **format_ptr,
				t_formatph *forma, va_list ap);
void			ft_scanlength(const char **format_ptr, t_formatph *forma);
void			ft_scantype(const char **format_ptr, t_formatph *forma);
#endif
