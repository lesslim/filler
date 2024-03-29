/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpstr_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:45:02 by rberon-s          #+#    #+#             */
/*   Updated: 2019/10/06 15:18:10 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rpstr.h"

static char		*ft_shift_p_u(char *ptr, uintmax_t val, int base,
		t_formatph forma)
{
	int			str_size;

	str_size = val == 0 ? 1 : 0;
	while (val)
	{
		str_size++;
		val /= base;
	}
	while (forma.precision != PRC_NO && forma.precision - str_size > 0)
	{
		*ptr++ = '0';
		str_size++;
	}
	return (ptr);
}

static char		*ft_shift_p(char *ptr, intmax_t val, int base,
		t_formatph forma)
{
	int			str_size;

	str_size = val == 0 ? 1 : 0;
	while (val)
	{
		str_size++;
		val /= base;
	}
	while (forma.precision != PRC_NO && forma.precision - str_size > 0)
	{
		*ptr++ = '0';
		str_size++;
	}
	return (ptr);
}

static void		ft_aux_u(uintmax_t val, int base, char **p,
		const char *base_str)
{
	int			tmp;

	if (val >= (uintmax_t)base)
		ft_aux_u(val / base, base, p, base_str);
	tmp = (int)(val % base);
	*(*p)++ = *(base_str + ft_abs(tmp));
}

static void		ft_aux(intmax_t val, int base, char **p, const char *base_str)
{
	int			tmp;

	if (val >= (intmax_t)base || val <= (intmax_t)(-base))
		ft_aux(val / base, base, p, base_str);
	tmp = (int)(val % base);
	*(*p)++ = *(base_str + ft_abs(tmp));
}

char			*pf_itoa_base(uintmax_t value, t_formatph forma)
{
	char		*ret;
	char		*p;
	int			size;
	int			base;
	const char	*base_str;

	base_str = forma.type == PFTP_CX ? "0123456789ABCDEF" : "0123456789abcdef";
	base = pf_get_base(forma);
	size = forma.precision > 70 ? (forma.precision + 1) : 70;
	if ((forma.precision == 0 && value == 0) || !(ret = (char *)malloc(size)))
		return (ft_strnew(0));
	if (forma.type <= PFTP_I && forma.type >= PFTP_D)
	{
		p = ft_shift_p(ret, value, base, forma);
		ft_aux(value, base, &p, base_str);
	}
	else
	{
		p = ft_shift_p_u(ret, value, base, forma);
		ft_aux_u(value, base, &p, base_str);
	}
	*p = 0;
	return (ret);
}
