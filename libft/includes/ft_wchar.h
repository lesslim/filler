/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:22:22 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include <wchar.h>
# include "libft.h"

size_t	ft_wstrlen(const wchar_t *wstr);
size_t	ft_widetoa(char *buf, wint_t w);
char	*ft_wstrtomb(const wchar_t *wstr);
size_t	ft_wstrntomb(char **buf, const wchar_t *wstr, size_t n);
#endif
